template <typename T>

class STACK
{
private:
    T* stack;
    int count;
public:
    void push(T item)
{
        T* tmp;
        tmp = stack;
        stack = new T[count + 1];

        count++;

        for (int i = 0; i < count - 1; i++)
        {
            stack[i] = tmp[i];
        }

        stack[count - 1] = item;

        if (count > 1)
        {
            delete[] tmp;
        }
    }
};
