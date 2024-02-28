#include <iostream>
#include<ctime>
using namespace std;

class ArrayList // Vector
{
	unsigned int size = 0; // количество действительно присутствующих элементов в контейнере
	unsigned int capacity = 10; // ёмкость (вместительность, запас памяти)
	int* data = nullptr; // указатель на динамический массив целых чисел
public:
	ArrayList() : ArrayList(10)
	{
		// cout << "C-TOR WITHOUT PARAMS!\n";
	}
	ArrayList(const ArrayList& original)
	{
		this->size = original.size;
		this->capacity = original.capacity;
		this->data = new int[size];
		for (int i = 0; i < size; i++)
		{
			this->data[i] = original.data[i];
		}		
	}
	ArrayList(unsigned int capacity)
	{
		if (capacity < 10)
		{
			capacity = 10;
		}
		this->capacity = capacity;
		data = new int[capacity];
		// cout << "C-TOR WITH PARAMS!\n";
	}

	~ArrayList()
	{
		// cout << "DESTRUCTOR!\n";
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}

	void PushBack(int value)
	{
		// EnsureCapacity(); // проверка, хватит ли места для нового элемента
		data[size] = value;
		size++;
	}

	void PushFront(int value)
	{
		// EnsureCapacity();
		for (int i = size; i > 0; i--) // i = 1
		{
			data[i] = data[i - 1]; // data[1] = data[0]
		}
		data[0] = value;
		size++;
	}

	void Clear()
	{
		size = 0;
	}

	bool IsEmpty() const
	{
		return size == 0;
	}

	void Print() const
	{
		if (IsEmpty())
		{
			cout << "Vector is empty.\n";
			return;
		}

		for (int i = 0; i < size; i++)
		{
			cout << data[i] << " ";
		}
		cout << "\n";
	}

	// ...остальные методы...
	unsigned int GetSize()
	{
		return size;
	}

	unsigned int GetCapacity()
	{
		return capacity;
	}

	void Insert(int element,int index)
	{
		bool ok = false;
		if (index >= 0 && index < size)
		{
			int* temp = new int[size + 1];
			for (int i = 0; i < size + 1; i++)
			{
				if (i == index)
				{
					ok = true;
					temp[i] = element;
					i++;
				}
				if (!ok)
					temp[i] = data[i];
				else
					temp[i] = data[i - 1];
			}
			delete[] data;
			size++;
			data = temp;
		}
		else
			throw "Error index\n";
	}

	void RemoveAt(int index)
	{
		bool ok = false;
		if (index >= 0 && index < size)
		{
			int* temp = new int[size - 1];
			for (int i = 0; i < size - 1; i++)
			{
				if (i == index)
				{
					temp[i] = data[i + 1];
					ok = true;
				}
				if (!ok)
					temp[i] = data[i];
				else
					temp[i] = data[i + 1];
			}
			delete[] data;
			size--;
			data = temp;
		}
		else
			throw "error index";
	}
	void PopBack()
	{
		int* temp = new int[size - 1];
		for (int i = 0; i < size - 1; i++)
		{
			temp[i] = data[i];
		}
		delete[] data;
		size--;
		data = temp;
	}

	void PopFront()
	{
		int* temp = new int[size - 1];
		for (int i = 1; i < size; i++)
		{
			temp[i - 1] = data[i];
		}
		delete[] data;
		size--;
		data = temp;
	}

	int IndexOf(int element)
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] == element)
			{
				return i;
			}

		}
		return -1;
	}

	int LastIndexOf(int element)
	{
		for (int i = size - 1; i >= 0; i--)
		{
			if (data[i] == element)
			{
				return i;
			}

		}
		return -1;
	}

	void Reverse()
	{
		int* temp = new int[size];
		for (int i = size - 1; i >= 0; i--)
		{
			temp[size - i - 1] = data[i];
		}
		delete[] data;
		data = temp;
	}

	void SortAz()
	{
		for (int i = 1; i < size - 1; i++)
		{
			for (int j = 0; j < size- i; j++)
			{
				if (data[j] > data[j + 1])
				{
					int temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}

	void SortZa()
	{
		/*SortAz();
		Reverse();*/
		for (int i = 1; i < size - 1; i++)
		{
			for (int j = 0; j < size - i; j++)
			{
				if (data[j] < data[j + 1])
				{
					int temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}
	void Shuffle()
	{
		
		int* temp = new int[size];
		int count1 = 0;
		while(count1 != 6)
		{
			for (int i = 0; i < size; i++)
			{
				int count = 0;
				int number = rand() % size;
				for (int j = 0; j < size; j++)
				{
					if (temp[number] != data[j])
					{
						count++;
					}
				}
				if (count == size)
				{
					count1++;
					temp[number] = data[i];
				}
				
				else
				{
					i--;
					number = rand() % size;
				}
			}
		}
		delete[] data;
		data = temp;

	}

	void SetCapacity(unsigned int capacity)
	{
		if (capacity < 10 + size)
		{
			capacity = 10 + size;
		}
	}

	void RandomFill()
	{
		for (int i = 0; i < size; i++)
		{
			data[i] = rand();
		}
	}
	bool operator == (ArrayList& array)
	{
		if (this->size == array.size)
		{
			return true;
		}
		else
			return false;
	}
	ArrayList& operator = (ArrayList& array)
	{
		this->capacity = array.capacity;
		this->size = array.size;
		this->data = new int[size];
		for (int i = 0; i < size; i++)
		{
			this->data[i] = array.data[i];
		}
		return *this;
	}
	int operator [](unsigned int index)
	{
		if (index < 0 && index > size)
			throw "error";
		return data[index];
	}
};
ostream& operator << (ostream& o, ArrayList& array)
{
	array.Print();
	return cout;
}
istream& operator >> (istream& i, ArrayList& array)
{
	unsigned int answer;
	cout << "Enter capacity - ";
	cin >> answer;
	array.SetCapacity(answer);
	return cin;
}

int main()
{
	srand(time(0));
	ArrayList ar;
	ar.Print();
	
	ar.PushBack(1);	
	ar.PushBack(2);
	ar.PushBack(3);
	ar.PushBack(4);
	ar.PushBack(5);	

	ar.Insert(12, 3);
	/*ArrayList list(ar);
	list.Print();*/
	/*cout << ar.IndexOf(4) << "\n";
	cout << ar.LastIndexOf(12) << "\n";*/
	/*ar.PopFront();*/
	//ar.Reverse();
	/*ar.SortAz();
	ar.SortZa();*/
	/*ar.RandomFill();*/
	//ar.Shuffle();
	ar.Print();
	cout << ar[3] << "\n";
	ArrayList list;
	cin >> list;
	list = ar;
	if (list == ar)
		cout << "Meow\n";
}