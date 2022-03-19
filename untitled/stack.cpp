template <typename T>

<<<<<<< HEAD
class STACK //класс для реализации стека
{
private:
    T* stack; //стек
    int count; //количество элементов в стеке

public:
    void push(T item) //добавление элемента в стек
{
        T* tmp; //временная переменная указатель
        tmp = stack;
        stack = new T[count + 1]; //выделение больше памяти в стеке чем было

        count++; //количество элементов в стеке увеличиваем

        for (int i = 0; i < count - 1; i++)
        {
            stack[i] = tmp[i]; //копируем данные из tmp (куда он указывает) в наш стек
        }

        stack[count - 1] = item; //добавляем последний элемент

        if (count > 1)
        {
            delete[] tmp; //освобождаем память
        }
    }

    T pop() //изъятие элемента из стека
        {
            T tmp;
            if (count == 0) //если наш стек пуст
                return tmp;
            count--; //уменьшаем количество элементов в стеке
            return stack[count]; //возвращаем  элемент стека
        }

        bool IsEmpty() //если наш стек пуст
        {
            return count == 0; //если количество элементов в стеке равна 0
=======
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

    T pop()
        {
            T tmp;
            if (count == 0)
                return tmp;
            count--;
            return stack[count];
        }

        bool IsEmpty()
        {
            return count == 0;
>>>>>>> main
        }

};
