#include <vector>

using namespace std;

template<typename Type>
class Set
{
private:

    vector<Type> array;

public:

    bool find(const Type& data)
    {
        for (auto& element : array)
        {
            if (data == element)
            {
                return true;
            }
        }
        return false;
    }

    void insert(const Type& data)
    {
        if (find(data))
        {
            return;
        }

        array.emplace_back(data);
    }

    void erase(const Type& data)
    {
        int i = 0;
        for (auto it = array.begin(); it <= array.end(); it++)
        {
            if (array[i] == data)
            {
                array.erase(it);
                return;
            }
            i++;
        }
        throw("The element isn't in the array");
    }

    void clear()
    {
        array.clear();
    }

    size_t size()
    {
        return array.size();
    }

    bool empty()
    {
        return array.empty();
    }
};