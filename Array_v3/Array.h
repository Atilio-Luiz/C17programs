#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T>
class Array;

template <typename T>
class IteratorArray {
private:
    friend class Array<T>; // indica que Array<T> é amiga da minha classe
    
    T* m_ptr;              // ponteiro para um elemento do tipo T
    
    // Construtor privado
    IteratorArray(T *ptr) : m_ptr{ptr} {}

public:
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T*;
    using reference = T&;

    // Construtor default
    IteratorArray() : IteratorArray(nullptr) {}

    // Sobrecarga do operador de pré-incremento
    IteratorArray& operator++() {
        m_ptr = m_ptr + 1;
        return *this;
    }
    
    // Sobrecarga do operador de pós-incremento
    IteratorArray operator++(int) {
        IteratorArray<T> itAux (m_ptr); // cópia do estado antes do incremento
        m_ptr = m_ptr + 1; // incremento do iterador
        return itAux; // retorno da cópia do estado anterior
    }
    
    // Sobrecarga do operador de igualdade
    // Como função-membro da classe
    bool operator==(const IteratorArray<T>& rhs) {
        return this->m_ptr == rhs.m_ptr;
    }
    
    // Sobrecarga do operador de diferença
    // Como função-membro da classe
    bool operator!=(const IteratorArray<T>& rhs) {
        return this->m_ptr != rhs.m_ptr;
    }
    
    // Sobrecarga do operador*
    reference operator*() {
        return *m_ptr;
    }
    
    // Sobrecarga do operador->
    pointer operator->() {
        return m_ptr;
    }
};

template <typename T>
class Array {
private:
    T* m_array {nullptr};
    std::size_t m_size {0};

public:
    using iterator = IteratorArray<T>;

    // Função que retorna um iterator apontando para o
    // primeiro elemento do array
    iterator begin() {
        return iterator(m_array);
    }

    // Função que retorna um iterator apontando para o
    // último bit do array
    iterator end() {
        return iterator(m_array + m_size);
    }

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