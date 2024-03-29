#include "tree.h"
#include "pile.h"

void init(Tree &tree)
{
    tree.value = nullptr;
    tree.smaller = nullptr;
    tree.bigger = nullptr;
}

bool is_tree_empty(const Tree &tree)
{
    return (tree.value == nullptr);
}

void set(Tree &tree, const char *SRC)
{
    if (!is_tree_empty(tree))
    {
        destroy(*tree.value);
        delete tree.value;
    }
    tree.value = new String;
    init(tree.value);
    set(*tree.value, SRC);
}

void add(Tree &tree, const char *SRC)
{
    assert(!is_tree_empty(tree));

    Tree * current_tree = &tree;
    bool finished = false;

    while (!finished)
    {
        long compare = strcmp(get(*current_tree->value), SRC);
        if (compare < 0)
        {

            if (current_tree->smaller != nullptr)
            {
                current_tree = current_tree->smaller;
            }
            else
            {
                current_tree->smaller = new Tree;

                init(*current_tree->smaller);
                set(*current_tree->smaller, SRC);
                finished = true;
            }
        }
        else if (compare > 0)
        {
            if (current_tree->bigger != nullptr)
            {
                current_tree = current_tree->bigger;
            }
            else
            {
                current_tree->bigger = new Tree;

                init(*current_tree->bigger);
                set(*current_tree->bigger, SRC);
                finished = true;
            }
        }
        else {
            break;
        }
    }
}

static void import_add(Tree &tree, char ** wordList, uint index)
{
    add(tree, wordList[index]);
    delete [] wordList[index];
    wordList[index] = nullptr;
}

static void import_loop(Tree &tree, char ** wordList, uint count)
{
    uint index = (count-1)/2;

    set(tree, wordList[index]); delete [] wordList[index]; wordList[index] = nullptr;

    File ranges{};
    ranges.first = nullptr;
    ranges.last = nullptr;

    Range currRange{};
    currRange.start = 0; currRange.end = index-1;
    add(ranges, currRange);

    currRange.start = index+1; currRange.end = count-1;
    add(ranges, currRange);

    while (!is_file_empty(ranges) || count > 1)
    {
        const Range range = get(head(ranges));
        remove(ranges);

        uint numberInRange = get_range(range);

        if (numberInRange == 1)
        {
            import_add(tree, wordList, range.end);
            --count;
        }
        else if (numberInRange == 2)
        {
            import_add(tree, wordList, range.start);
            import_add(tree, wordList, range.end);
            count -= 2;
        }
        else if (numberInRange > 0)
        {
            index = range.start+((range.end - range.start)/2)+1;
            --count;
            import_add(tree, wordList, index);

            currRange.start = range.start;
            currRange.end = index - 1;
            add(ranges, currRange);

            currRange.start = index + 1;
            currRange.end = range.end;
            add(ranges, currRange);
        }
    }

    destroy(ranges);
}

String * starts_with(Tree &tree, const char *WORD)
{
    Tree * currentTree = &tree;
    while (currentTree != nullptr) {
        if (strstr(get(currentTree->value), WORD) == get(currentTree->value))
        {
            return currentTree->value;
        }
        else if (strcmp(get(*currentTree->value), WORD) > 0)
        {
            if (currentTree->bigger != nullptr) currentTree = currentTree->bigger;
            else currentTree = nullptr;
        }
        else
        {
            if (currentTree->smaller != nullptr) currentTree = currentTree->smaller;
            else currentTree = nullptr;
        }
    }
    return nullptr;
}

String * starts_with(Tree &tree, const String &WORD)
{
    return starts_with(tree, WORD.value);
}

void import(Tree &tree, const char *PATH)
{
    std::ifstream in(PATH);
    assert (in);

    uint lineCount = get_line_count(in);
    assert (lineCount > 0);

    in.clear();
    in.seekg(0);

    char ** wordList = new char *[lineCount];

    uint count = 0;

    while (in)
    {
        wordList[count] = new char[MAX_WORD_SIZE];
        in >> std::setw(MAX_WORD_SIZE) >> wordList[count];
        ++count;
    }
    in.close();

    import_loop(tree, wordList, count-1);
}

bool search(Tree &tree, const char *SRC)
{
    Tree * currentTree = &tree;
    while (currentTree != nullptr)
    {
        int compare = std::strcmp(get(*currentTree->value), SRC);
        if (compare < 0) currentTree = currentTree->smaller;
        else if (compare > 0) currentTree = currentTree->bigger;
        else return true;
    }
    return false;
}

bool search(Tree &tree, const String &SRC)
{
    return search(tree, get(SRC));
}

void destroy(Tree &tree)
{
    Tree * currentTree = &tree;

    if (currentTree == nullptr) return;

    Pile tempPile{};
    Pile cleanUpPile{};
    tempPile.last = nullptr;
    cleanUpPile.last = nullptr;

    add(tempPile, currentTree);

    while (!is_pile_empty(tempPile))
    {
        currentTree = get(*head(tempPile));
        add(cleanUpPile, currentTree);
        remove(tempPile);

        if (currentTree->bigger != nullptr)
            add(tempPile, currentTree->bigger);
        if (currentTree->smaller != nullptr)
            add(tempPile, currentTree->smaller);
    }

    while(!is_pile_empty(cleanUpPile))
    {
        currentTree = get(*head(cleanUpPile));
        remove(cleanUpPile);
        if (currentTree != &tree)
            delete currentTree;
    }
}