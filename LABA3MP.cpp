#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <locale.h>
#include <chrono>
#include <map>
#include <set>

using namespace std;

/**
    @brief Первая хэш-функция
    @param Строка, хэш которой необходимо найти
    @return Беззнаковое целое число - хэш строки
*/

unsigned int hash1(std::string key) {
    unsigned int ans = 1;
    for (int i = 0; i < key.size(); i++)
        ans *= (key[i] - 'a');

    return ans;
}


/**
    @brief Вторая хэш-функция
    @param Строка, хэш которой необходимо найти
    @return Беззнаковое целое число - хэш строки
*/
unsigned int hash2(std::string key) {
    unsigned int ans = 0;

    for (int i = 0; i < key.size(); i++)
        ans = 37 * ans + (key[i] - 'a');

    return ans;
}

/**
 *  @brief Класс Бухгалтера, хранящий информацию о ФИО, должности, подразделении и азрплате, а также обладающий методами для взаимодействия объектов класса.
 */

class Accountant {
public:
    /**
 *  @brief Конструктор по умолчанию
 *  @details Заполняет поля класса пустыми строками
 *  @param Параметры отсутствуют
 *  @return Возвращаемое значение отсутствует
 *
 *  Реализация:
 *
 *  @code
    Accountant::Accountant() {
        fname = "";
        lname = "";
        mname = "";
        title = "";
        subdiv = "";
        salary = 0;
    }
 *  @endcode
 */

    std::string fname;
    std::string lname;
    std::string mname;
    std::string title;
    std::string subdiv;
    int salary;

    Accountant();
    /**
 *  @brief Конструктор из файлового потока
 *  @details Считывает поля класса из передаваемого файлового потока
 *  @param Ссылка на файловый поток ввода
 *  @return Возвращаемое значение отсутствует
 *
 *  Реализация:
 *
 *  @code
    Accountant::Accountant(ifstream& in) {
        in >> fname >> lname >> mname >> title >> subdiv >> salary;
    }
 *  @endcode
 */
    Accountant(std::ifstream& in);
    /**
 *  @brief Деструктор класса
 *  @param Параметры отсутствуют
 *  @return Возвращаемое значение отсутствует
 *
 *  Реализация:
 *
 *  @code
    Accountant::~Accountant(){
    }
 *  @endcode
 */
    ~Accountant();
    /**
 *  @brief Оператор присваивания
 *  @details Присваивает объекту данного класса значения полей правого операнда этого же класса
 *  @param Константная ссылка на объект такого же класса
 *  @return Ссылка на этот же объект для возможности дальнейших преобразований компилятором
 *
 *  Реализация:
 *
 *  @code
    Accountant& Accountant::operator= (const Accountant& A) {
        fname = A.fname;
        lname = A.lname;
        mname = A.mname;
        title = A.title;
        subdiv = A.subdiv;
        salary = A.salary;

        return *this;
    }
 *  @endcode
 */
    Accountant& operator= (const Accountant& A);
    /**
 *  @brief Оператор вывода
 *  @details Дружественный оператор вывода полей класса в поток
 *  @param Ссылка на поток вывода и константная ссылка на выводимый объект
 *  @return Ссылка на поток вывода для возможности дальнейших преобразований компилятором
 *
 *  Реализация:
 *
 *  @code
    ostream& operator<< (ostream& out, const Accountant& A) {
        out << A.fname << " ";
        out << A.lname << " ";
        out << A.mname << " ";
        out << A.title << " ";
        out << A.subdiv << " ";
        out << A.salary << " ";
        out << endl;

        return out;
    }
 *  @endcode
 */
    friend std::ostream& operator<< (std::ostream& out, const Accountant& A);
};

Accountant::Accountant() {
    fname = "";
    lname = "";
    mname = "";
    title = "";
    subdiv = "";
    salary = 0;
}

Accountant::Accountant(std::ifstream& in) {
    in >> fname >> lname >> mname >> title >> subdiv >> salary;
}

Accountant::~Accountant() {

}

Accountant& Accountant::operator= (const Accountant& A) {
    fname = A.fname;
    lname = A.lname;
    mname = A.mname;
    title = A.title;
    subdiv = A.subdiv;
    salary = A.salary;

    return *this;
}

std::ostream& operator<< (std::ostream& out, const Accountant& A) {
    out << A.fname << " ";
    out << A.lname << " ";
    out << A.mname << " ";
    out << A.title << " ";
    out << A.subdiv << " ";
    out << A.salary << " ";
    out << std::endl;

    return out;
}
/**
    @brief Оператор равенства для двух объектов класса Accountant
    @param Две константные ссылки на сравниваемые объекты
    @return True, если поля объектов равны, False иначе.
*/
bool operator== (const Accountant& A, const Accountant& B) {
    return ((A.fname == B.fname) &&
        (A.lname == B.lname) &&
        (A.mname == B.mname) &&
        (A.title == B.title) &&
        (A.subdiv == B.subdiv) &&
        (A.salary == B.salary));
}
/**
    @brief Оператор неравенства для двух объектов класса Accountant
    @param Две константные ссылки на сравниваемые объекты
    @return False, если поля объектов равны, True иначе.
*/
bool operator!= (const Accountant& A, const Accountant& B) {
    return !(A == B);
}
/**
    @brief Оператор больше для двух объектов класса Accountant
    @param Две константные ссылки на сравниваемые объекты
    @return True, если при сравнении полей по приоритетам, некоторое поле первого объекта лексически больше, чем соответствующее поле второго объекта, False иначе.
*/
bool operator> (const Accountant& A, const Accountant& B) {
    if (A == B)
        return false;

    if (A.subdiv != B.subdiv)
        return (A.subdiv > B.subdiv);

    if (A.fname != B.fname)
        return (A.fname > B.fname);

    if (A.lname != B.lname)
        return (A.lname > B.lname);

    if (A.mname != B.mname)
        return (A.mname > B.mname);

    if (A.salary != B.salary)
        return (A.salary > B.salary);

    return false;
}
/**
    @brief Оператор меньше для двух объектов класса Accountant
    @param Две константные ссылки на сравниваемые объекты
    @return True, если при сравнении полей по приоритетам, некоторое поле первого объекта лексически меньше, чем соответствующее поле второго объекта, False иначе.
*/
bool operator< (const Accountant& A, const Accountant& B) {
    return (A != B && !(A > B));
}
/**
    @brief Оператор больше либо равно для двух объектов класса Accountant
    @param Две константные ссылки на сравниваемые объекты
    @return True, если при сравнении полей по приоритетам, некоторое поле первого объекта лексически больше, чем соответствующее поле второго объекта, или объекты равны, False иначе.
*/
bool operator >= (const Accountant& A, const Accountant& B) {
    return (A == B || A > B);
}
/**
    @brief Оператор меньше либо равно для двух объектов класса Accountant
    @param Две константные ссылки на сравниваемые объекты
    @return True, если при сравнении полей по приоритетам, некоторое поле первого объекта лексически меньше, чем соответствующее поле второго объекта, или объекты равны, False иначе.
*/
bool operator <= (const Accountant& A, const Accountant& B) {
    return (A == B || A < B);
}
/**
    @brief Шаблонная функция сортировки Insert Sort
    @param Сортируемый массив в виде указателя на первый элемент и размер массива
    @return Возвращаемое значение отсутствует
*/
template <typename T>
void insertSort(T* A, size_t n) {

    T x;
    long int i = 0, j = 0;
    for (int i = 1; i < n; i++) {
        x = A[i];
        for (j = i - 1; j >= 0 && A[j] > x; j--) {
            A[j + 1] = A[j];
        }
        A[j + 1] = x;
    }

}

template <typename T>
void selectSort(T* A, size_t size)
{
    long i, j, k;
    T x;
    for (i = 0; i < size - 1; i++)
    {   							// i - current step
        k = i;
        x = A[i];
        for (j = i + 1; j < size; j++)	// loop for searching minimal element
        {
            if (A[j] < x)
            {
                k = j; x = A[j];	        // k - minimal element index
            }
        }
        A[k] = A[i]; A[i] = x;   	// swap minimal element and a[i]
    }
}

/**
    @brief Шаблонная функция сортировки Shaker Sort
    @param Сортируемый массив в виде указателя на первый элемент и размер массива
    @return Возвращаемое значение отсутствует
*/
template <typename T>
void shakerSort(T* A, size_t n) {
    long j, k = n - 1;
    long lb = 1, ub = n - 1;
    T x;
    do {
        for (j = ub; j > 0; j--) {
            if (A[j - 1] > A[j]) {
                x = A[j - 1];
                A[j - 1] = A[j];
                A[j] = x;
                k = j;
            }
        }
        lb = k + 1;
        for (j = 1; j <= ub; j++) {
            if (A[j - 1] > A[j]) {
                x = A[j - 1];
                A[j - 1] = A[j];
                A[j] = x;
                k = j;
            }
        }
        ub = k - 1;
    } while (lb < ub);
}
/**
    @brief Шаблонная функция сортировки Merge Sort
    @param Сортируемый массив в виде указателя на первый элемент и размер массива
    @return Возвращаемое значение отсутствует
*/
template <typename T>
void mergeSort(T* A, size_t n) {
    if (n == 1)
        return;

    mergeSort(A, n / 2);
    mergeSort(&A[n / 2], n - n / 2);

    size_t i = 0, j = n / 2, k = 0;

    T* tmp = new Accountant[n];

    while (k < n) {
        if (i == n / 2) {
            tmp[k] = A[j];
            j++;
        }
        else
            if (j == n) {
                tmp[k] = A[i];
                i++;
            }
            else
                if (A[i] < A[j]) {
                    tmp[k] = A[i];
                    i++;
                }
                else
                {
                    tmp[k] = A[j];
                    j++;
                }
        k++;
    }

    for (size_t i = 0; i < n; i++)
        A[i] = tmp[i];
}
/**
    @brief Шаблонная функция прямого поиска
    @param Массив A, в котором будет производиться поиск, размер массива n и ключ поиска keyName
    @return Индекс искомого элемента в массиве. -1 если элемент с таким ключом отсутствует
*/
template <typename T>
int linearSearch(T* A, size_t n, std::string keyName) {
    for (size_t i = 0; i < n; i++)
        if (A[i].fname == keyName)
            return i;
    return -1;
}
/**
    @brief Шаблонная функция бинарного поиска
    @param Массив A, в котором будет производиться поиск, размер массива n и ключ поиска keyName
    @return Индекс искомого элемента в массиве. -1 если элемент с таким ключом отсутствует
*/
template <typename T>
int binarySearch(T* A, size_t n, std::string keyName) {

    size_t left = 0, right = n, mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (A[mid].fname == keyName)
            return mid;
        if (A[mid].fname > keyName)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}
/**
    @brief Глобальные переменные для хранения массивов данных
*/
Accountant* data100 = new Accountant[100],
* data500 = new Accountant[500],
* data1000 = new Accountant[1000],
* data5000 = new Accountant[5000],
* data10000 = new Accountant[10000],
* data50000 = new Accountant[50000],
* data100000 = new Accountant[100000];

/**
    @brief Функция для ввода данных из внешних файлов
    @param Параметров нет
    @return Возвращаемое значение отсутствует
*/
void readData() {
    std::ifstream in100("100.txt");

    if (in100.is_open())
        for (size_t i = 0; i < 100; i++)
            data100[i] = Accountant(in100);
    in100.close();


    std::ifstream in500("500.txt");
    if (in500.is_open())
        for (size_t i = 0; i < 500; i++)
            data500[i] = Accountant(in500);
    in500.close();

    std::ifstream in1000("1000.txt");
    if (in1000.is_open())
        for (size_t i = 0; i < 1000; i++)
            data1000[i] = Accountant(in1000);
    in1000.close();

    std::ifstream in5000("5000.txt");
    if (in5000.is_open())
        for (size_t i = 0; i < 5000; i++)
            data5000[i] = Accountant(in5000);
    in5000.close();

    std::ifstream in10000("10000.txt");
    if (in10000.is_open())
        for (size_t i = 0; i < 10000; i++)
            data10000[i] = Accountant(in10000);
    in10000.close();

    std::ifstream in50000("50000.txt");
    if (in50000.is_open())
        for (size_t i = 0; i < 50000; i++)
            data50000[i] = Accountant(in50000);
    in50000.close();

    std::ifstream in100000("100000.txt");
    if (in100000.is_open())
        for (size_t i = 0; i < 100000; i++)
            data100000[i] = Accountant(in100000);
    in100000.close();
}
/**
 *  @brief Класс хэш-таблицы, использующей первую хэш-функцию
 */
class HashTable1 {
public:
    Accountant** table;
    unsigned int sizes[20000] = { 0 };

    HashTable1() {

    }
    /**
 *  @brief Конструктор из массива данных
 *  @details Создает хэш-таблицу по передаваемому массиву объектов
 *  @param Массив данных с объектами типа Prepod, целое число n - количество элементов массива
 *  @return Возвращаемое значение отсутствует
 *
 *  Реализация:
 *
 *  @code
    HashTable1(Accountant* data, size_t n){
        int counter = 0;

        table = new Accountant* [20000];

        cout << "Creating hash table from data with value of " << n << endl;

        for (size_t i = 0; i < 20000; i++)
            table[i] = nullptr;

        for (size_t i = 0; i < n; i++){
            unsigned int hash = hash1(data[i].getFname());
            if (table[hash] == nullptr){
                table[hash] = new Accountant [1];
                table[hash][0] = data[i];
                sizes[hash] = 1;
            }
            else
            {
                counter++;
                unsigned int old_n = sizes[hash];
                Prepod* tmp = new Accountant [old_n + 1];
                for (size_t j = 0; j < old_n; j++)
                    tmp[j] = table[hash][j];
                tmp[old_n] = data[i];
                table[hash] = tmp;
                sizes[hash]++;
            }
        }

        cout << counter << " collisions" << endl;
    }
 *  @endcode
 */
    HashTable1(Accountant* data, size_t n) {
        int counter = 0;

        table = new Accountant * [20000];

        std::cout << "Creating hash table from data with value of " << n << std::endl;

        for (size_t i = 0; i < 20000; i++)
            table[i] = nullptr;

        for (size_t i = 0; i < n; i++) {
            unsigned int hash = hash1(data[i].fname);
            if (table[hash] == nullptr) {
                table[hash] = new Accountant[1];
                table[hash][0] = data[i];
                sizes[hash] = 1;
            }
            else
            {
                counter++;
                unsigned int old_n = sizes[hash];
                Accountant* tmp = new Accountant[old_n + 1];
                for (size_t j = 0; j < old_n; j++)
                    tmp[j] = table[hash][j];
                tmp[old_n] = data[i];
                table[hash] = tmp;
                sizes[hash]++;
            }
        }

        std::cout << counter << " collisions" << std::endl;
    }
};
/**
 *  @brief Класс хэш-таблицы, использующей вторую хэш-функцию
 */
class HashTable2 {
public:
    Accountant** table;
    unsigned int sizes[40000] = { 0 };

    HashTable2() {

    }
    /**
 *  @brief Конструктор из массива данных
 *  @details Создает хэш-таблицу по передаваемому массиву объектов
 *  @param Массив данных с объектами типа Prepod, целое число n - количество элементов массива
 *  @return Возвращаемое значение отсутствует
 *
 *  Реализация:
 *
 *  @code
    HashTable2(Accountant* data, size_t n){
        int counter = 0;

        table = new Accountant* [40000];

        cout << "Creating hash table from data with value of " << n << endl;

        for (size_t i = 0; i < 40000; i++)
            table[i] = nullptr;

        for (size_t i = 0; i < n; i++){
            unsigned int hash = hash2(data[i].getFname());
            if (table[hash] == nullptr){
                table[hash] = new Accountant [1];
                table[hash][0] = data[i];
                sizes[hash] = 1;
            }
            else
            {
                counter++;
                unsigned int old_n = sizes[hash];
                Accountant* tmp = new Accountant [old_n + 1];
                for (size_t j = 0; j < old_n; j++)
                    tmp[j] = table[hash][j];
                tmp[old_n] = data[i];
                table[hash] = tmp;
                sizes[hash]++;
            }
        }

        cout << counter << " collisions" << endl;
    }
 *  @endcode
 */
    HashTable2(Accountant* data, size_t n) {
        int counter = 0;

        table = new Accountant * [40000];

        std::cout << "Creating hash table from data with value of " << n << std::endl;

        for (size_t i = 0; i < 40000; i++)
            table[i] = nullptr;

        for (size_t i = 0; i < n; i++) {
            unsigned int hash = hash2(data[i].fname);
            if (table[hash] == nullptr) {
                table[hash] = new Accountant[1];
                table[hash][0] = data[i];
                sizes[hash] = 1;
            }
            else
            {
                counter++;
                unsigned int old_n = sizes[hash];
                Accountant* tmp = new Accountant[old_n + 1];
                for (size_t j = 0; j < old_n; j++)
                    tmp[j] = table[hash][j];
                tmp[old_n] = data[i];
                table[hash] = tmp;
                sizes[hash]++;
            }
        }

        std::cout << counter << " collisions" << std::endl;
    }
};
/**
    @brief Функция поиска объектов по ключу c использованием хэш-таблицы по первой функции
    @param Хэш таблица и искомый ключ
    @return Искомый объект типа Prepod. Если он не был найден, возвращаемым значением будет объект типа Prepod по умолчанию
*/
Accountant findWithHashTable(HashTable1 hashTable, std::string key) {
    unsigned int hash = hash1(key);

    if (hashTable.table[hash] == nullptr)
        return Accountant();
    else
    {
        for (int i = 0; i < hashTable.sizes[hash]; i++)
            if (hashTable.table[hash][i].fname == key)
                return hashTable.table[hash][i];
        return Accountant();
    }
}
/**
    @brief Функция поиска объектов по ключу c использованием хэш-таблицы по второй функции
    @param Хэш таблица и искомый ключ
    @return Искомый объект типа Prepod. Если он не был найден, возвращаемым значением будет объект типа Prepod по умолчанию
*/
Accountant findWithHashTable(HashTable2 hashTable, std::string key) {
    unsigned int hash = hash2(key);

    if (hashTable.table[hash] == nullptr)
        return Accountant();
    else
    {
        for (int i = 0; i < hashTable.sizes[hash]; i++)
            if (hashTable.table[hash][i].fname == key)
                return hashTable.table[hash][i];
        return Accountant();
    }
}

/**
    @brief Функция main
    @param Считывание выборок разного объема из файлов, выбор метода поиска и вывод на экран затраченного на поиск времени
    @return Возвращаемое значение - код завершения программы

    Реализация:

    @code
    int main() {
    //setlocale(LC_ALL, "Russian");

    readData();

    std::cout << "Data has read" << std::endl;

    int choice;

    std::cout << "Which hash-function you'll test:\n\n1. Simple\n2. Hard\n\n";
    std::cin >> choice;
    std::cout << std::endl << std::endl;
    if (choice == 1) {
        HashTable1 ht100(data100, 100),
            ht500(data500, 500),
            ht1000(data1000, 1000),
            ht5000(data5000, 5000),
            ht10000(data10000, 10000),
            ht50000(data50000, 50000),
            ht100000(data100000, 100000);




        std::cout << "Data sampling with a volume of 100:\t";
        auto start_t = std::chrono::steady_clock::now();
        auto tmp = findWithHashTable(ht100, "fmw");
        auto end_t = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

        std::cout << "Data sampling with a volume of 500:\t";
        start_t = std::chrono::steady_clock::now();
        tmp = findWithHashTable(ht500, "byu");
        end_t = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

        std::cout << "Data sampling with a volume of 1000:\t";
        start_t = std::chrono::steady_clock::now();
        tmp = findWithHashTable(ht1000, "lga");
        end_t = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

        std::cout << "Data sampling with a volume of 5000:\t";
        start_t = std::chrono::steady_clock::now();
        tmp = findWithHashTable(ht5000, "ocy");
        end_t = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

        std::cout << "Data sampling with a volume of 10000:\t";
        start_t = std::chrono::steady_clock::now();
        tmp = findWithHashTable(ht10000, "wmc");
        end_t = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

        std::cout << "Data sampling with a volume of 50000:\t";
        start_t = std::chrono::steady_clock::now();
        tmp = findWithHashTable(ht50000, "thl");
        end_t = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

        std::cout << "Data sampling with a volume of 100000:\t";
        start_t = std::chrono::steady_clock::now();
        tmp = findWithHashTable(ht100000, "ntx");
        end_t = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

    }
    if (choice == 2) {
        HashTable2 ht100(data100, 100),
            ht500(data500, 500),
            ht1000(data1000, 1000),
            ht5000(data5000, 5000),
            ht10000(data10000, 10000),
            ht50000(data50000, 50000),
            ht100000(data100000, 100000);




        std::cout << "Data sampling with a volume of 100:\t";
        auto start_t = std::chrono::steady_clock::now();
        auto tmp = findWithHashTable(ht100, "fmw");
        auto end_t = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

        std::cout << "Data sampling with a volume of 500:\t";
        start_t = std::chrono::steady_clock::now();
        tmp = findWithHashTable(ht500, "byu");
        end_t = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

        std::cout << "Data sampling with a volume of 1000:\t";
        start_t = std::chrono::steady_clock::now();
        tmp = findWithHashTable(ht1000, "lga");
        end_t = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

        std::cout << "Data sampling with a volume of 5000:\t";
        start_t = std::chrono::steady_clock::now();
        tmp = findWithHashTable(ht5000, "ocy");
        end_t = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

        std::cout << "Data sampling with a volume of 10000:\t";
        start_t = std::chrono::steady_clock::now();
        tmp = findWithHashTable(ht10000, "wmc");
        end_t = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

        std::cout << "Data sampling with a volume of 50000:\t";
        start_t = std::chrono::steady_clock::now();
        tmp = findWithHashTable(ht50000, "thl");
        end_t = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

        std::cout << "Data sampling with a volume of 100000:\t";
        start_t = std::chrono::steady_clock::now();
        tmp = findWithHashTable(ht100000, "ntx");
        end_t = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

    }
}
    @endcode
*/

int main() {
    //setlocale(LC_ALL, "Russian");

    readData();

    std::cout << "Data has read" << std::endl;

    int choice;

    std::cout << "Which hash-function you'll test:\n\n1. Simple\n2. Hard\n\n";
    std::cin >> choice;
    std::cout << std::endl << std::endl;
    if (choice == 1) {
        HashTable1 ht100(data100, 100),
            ht500(data500, 500),
            ht1000(data1000, 1000),
            ht5000(data5000, 5000),
            ht10000(data10000, 10000),
            ht50000(data50000, 50000),
            ht100000(data100000, 100000);




        std::cout << "Data sampling with a volume of 100:\t";
        auto start_t = std::chrono::steady_clock::now();
        auto tmp = findWithHashTable(ht100, "fmw");
        auto end_t = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

        std::cout << "Data sampling with a volume of 500:\t";
        start_t = std::chrono::steady_clock::now();
        tmp = findWithHashTable(ht500, "byu");
        end_t = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

        std::cout << "Data sampling with a volume of 1000:\t";
        start_t = std::chrono::steady_clock::now();
        tmp = findWithHashTable(ht1000, "lga");
        end_t = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

        std::cout << "Data sampling with a volume of 5000:\t";
        start_t = std::chrono::steady_clock::now();
        tmp = findWithHashTable(ht5000, "ocy");
        end_t = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

        std::cout << "Data sampling with a volume of 10000:\t";
        start_t = std::chrono::steady_clock::now();
        tmp = findWithHashTable(ht10000, "wmc");
        end_t = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

        std::cout << "Data sampling with a volume of 50000:\t";
        start_t = std::chrono::steady_clock::now();
        tmp = findWithHashTable(ht50000, "thl");
        end_t = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

        std::cout << "Data sampling with a volume of 100000:\t";
        start_t = std::chrono::steady_clock::now();
        tmp = findWithHashTable(ht100000, "ntx");
        end_t = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

    }
    if (choice == 2) {
        HashTable2 ht100(data100, 100),
            ht500(data500, 500),
            ht1000(data1000, 1000),
            ht5000(data5000, 5000),
            ht10000(data10000, 10000),
            ht50000(data50000, 50000),
            ht100000(data100000, 100000);




        std::cout << "Data sampling with a volume of 100:\t";
        auto start_t = std::chrono::steady_clock::now();
        auto tmp = findWithHashTable(ht100, "fmw");
        auto end_t = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

        std::cout << "Data sampling with a volume of 500:\t";
        start_t = std::chrono::steady_clock::now();
        tmp = findWithHashTable(ht500, "byu");
        end_t = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

        std::cout << "Data sampling with a volume of 1000:\t";
        start_t = std::chrono::steady_clock::now();
        tmp = findWithHashTable(ht1000, "lga");
        end_t = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

        std::cout << "Data sampling with a volume of 5000:\t";
        start_t = std::chrono::steady_clock::now();
        tmp = findWithHashTable(ht5000, "ocy");
        end_t = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

        std::cout << "Data sampling with a volume of 10000:\t";
        start_t = std::chrono::steady_clock::now();
        tmp = findWithHashTable(ht10000, "wmc");
        end_t = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

        std::cout << "Data sampling with a volume of 50000:\t";
        start_t = std::chrono::steady_clock::now();
        tmp = findWithHashTable(ht50000, "thl");
        end_t = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

        std::cout << "Data sampling with a volume of 100000:\t";
        start_t = std::chrono::steady_clock::now();
        tmp = findWithHashTable(ht100000, "ntx");
        end_t = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_t - start_t);
        std::cout << elapsed_ms.count() << " nanoseconds\n";

    }
}


