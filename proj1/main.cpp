#include <iostream>

namespace xd {
	template <typename T>
	class Vector {
		const size_t INITIAL_CAPACITY = 4;

		T *m_array;
		size_t m_size;
		size_t m_capacity;

	public:
		Vector() {
			m_array = new T[INITIAL_CAPACITY];
			m_size = 0;
			m_capacity = INITIAL_CAPACITY;
		}


		~Vector() {
			std::cout << "Deleted vector with size " << m_size << std::endl;
			delete[] m_array;
		}

		size_t size() {
			return m_size;
		}

		void add(T value) {
			if(m_size == m_capacity) {
				size_t new_capacity = m_capacity * 2;
				T *new_array = new T[new_capacity];
				for(size_t i = 0; i < m_capacity; i++) {
					new_array[i] = m_array[i];
				}
				delete[] m_array;
				m_capacity = new_capacity;
				m_array = new_array;
			}

			m_array[m_size] = value;
			m_size++;
		}

		// Indexer (индексатор)
		T &operator[](size_t index) {
			if(index >= m_size) {
				throw std::invalid_argument("Index was outside of array bounds");
			}

			return m_array[index];
		}

		Vector operator+(Vector &other) {
			Vector new_vec;

			for(size_t i = 0; i < m_size; i++) {
				new_vec.add(m_array[i]);
			}

			for(size_t i = 0; i < other.size(); i++) {
				new_vec.add(other[i]);
			}

			return new_vec;
		}

		// void remove(size_t index)
		// void insert(size_t index, T value)
		// void print()
		// Vector(const Vector &other) // Конструктор копирования
	};
}


int main() {
	using namespace xd;
	Vector<int> vec;
	int b = 2 + 4;

	vec.add(5);
	vec.add(3);
	vec.add(9);
	int &a = vec[1];
	a = 99;

	Vector<int> vec2;
	vec2.add(-10);
	vec2.add(18);

	Vector<int> vec3 = vec + vec2;
	for(size_t i = 0; i < vec3.size(); i++) {
		std::cout << vec3[i] << " ";
	}
	std::cout << std::endl;

	// Здесь программа вылетит нахуй
	// std::cout << vec3[99] << std::endl;

	return 0;
}
