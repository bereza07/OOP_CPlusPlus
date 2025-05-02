#include <memory>
#include <iostream>

template <typename T>
class Queue {
private:
	std::unique_ptr<T[]> m_queue;
	size_t m_size;
	size_t m_capacity;

public:
	Queue(size_t initCap = 2) :
		m_capacity(initCap),
		m_size(0),
		m_queue(std::make_unique<T[]>(initCap))
	{}

	void push(const T& item) {
		if (m_size >= m_capacity) {
			size_t newCap = m_capacity + 2;
			auto newQueue = std::make_unique<T[]>(newCap);

			for (size_t i = 0; i < m_size; i++) {
				newQueue[i] = std::move(m_queue[i]);
			}

			m_queue = std::move(newQueue);
			m_capacity = newCap;
		}
		m_queue[m_size++] = item;
	}

	void pop() {
		if (m_size <= 0) {
			throw std::invalid_argument("Array is empty!");
		}
		auto newQueue = std::make_unique<T[]>(m_size - 1);

		for (size_t i = 0; i < m_size - 1; i++) {
			newQueue[i] = std::move(m_queue[i]);
		}
		m_queue = std::move(newQueue);
		m_size--;
	}

	void displayInfo() {
		std::cout << "Queue: \n";
		for (size_t i = 0; i < m_size; i++) {
			std::cout << "Element " << i << ": " << m_queue[i] << std::endl;
		}
	}
};

int main() {
	try {
		Queue<int> intQueue;
		intQueue.push(12);
		intQueue.displayInfo();
		intQueue.pop();
		intQueue.pop();
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
