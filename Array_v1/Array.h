#ifndef ARRAY_H
#define ARRAY_H
#include <stdexcept>

template <typename T>
class Array {
private:
    T* m_array {nullptr};
    std::size_t m_size {0};
public:
    // Construtor default deletado
    Array() = delete;

    // Construtor
    Array(std::size_t n) {
        m_array = new T[n];
        m_size = n;
    }
    // Copy Constructor
    // Recebe um array previamente criado e 
    // faz uma cópia dele
    Array(const Array& other) {
        m_size = other.m_size;
        m_array = new T[m_size];
        for(int i{0}; i < m_size; ++i) {
            m_array[i] = other.m_array[i];
        }
    }
    // Destrutor
    ~Array() {
        delete[] m_array;
    }
    // Função que devolve o tamanho do array
    std::size_t size() const {
        return m_size;
    }
    // Sobrecarga do operador de atribuição (=)
    Array& operator=(const Array& other) {
        if(m_array != other.m_array) {
            delete[] m_array;
            m_size = other.m_size;
            m_array = new T[m_size];
            for(int i{0}; i < m_size; ++i) {
                m_array[i] = other.m_array[i];
            }
        }
        return *this;
    }
    // Sobrecarga do operador[]
    T& operator[](int index) {
        if(index >= 0 && index < static_cast<int>(m_size)) {
            return m_array[index];
        }
        else {
            throw std::out_of_range("index out of range");
        }
    }
    const T& operator[](int index) const {
        if(index >= 0 && index < m_size) {
            return m_array[index];
        }
        else {
            throw std::out_of_range("index out of range");
        }
    }
    // Faz o swap (troca) de dois Arrays
    void swap(Array& other) {
        std::swap(m_size, other.m_size);
        std::swap(m_array, other.m_array);
    }

};


// Funções globais
template <typename T>
bool operator==(const Array<T>& left, const Array<T>& right) {
    if(left.size() != right.size())
        return false;
    // os arrays tem o mesmo tamanho, checar elemento a elemento
    for(int i{0}; i < left.size(); ++i) {
        if(left[i] != right[i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
bool operator!=(const Array<T>& left, const Array<T>& right) {
    return !(left == right);
}

#endif