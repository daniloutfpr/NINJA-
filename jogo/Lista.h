#include <iostream>
#include "Entidade.h"
#include <cstddef> // Para nullptr

namespace Lista {

    template <typename T>
    class Lista {
    private:
        // Classe interna Node (nó)
        struct Elemento {
            T data;
            Elemento* proximo;
            Elemento* anterior;

            Elemento(const T& valor) : data(valor), proximo(nullptr), anterior(nullptr) {}
        };

        Elemento* inicio; // Primeiro elemento da lista
        Elemento* fim;    // Último elemento da lista
        size_t tamanho;   // Quantidade de elementos na lista

    public:
        // Classe Iterator aninhada (Iterator)
        class Iterator {
        private:
            Elemento* atual;

        public:
            explicit Iterator(Elemento* elemento = nullptr) : atual(elemento) {}

            T& operator*() const { return atual->data; }

            Iterator& operator++() {
                atual = atual->proximo;
                return *this;
            }

            Iterator operator++(int) {
                Iterator temp = *this;
                ++(*this);
                return temp;
            }

            Iterator& operator--() {
                atual = atual->anterior;
                return *this;
            }

            Iterator operator--(int) {
                Iterator temp = *this;
                --(*this);
                return temp;
            }

            bool operator==(const Iterator& outro) const { return atual == outro.atual; }
            bool operator!=(const Iterator& outro) const { return atual != outro.atual; }
        };

        // Construtor
        Lista() : inicio(nullptr), fim(nullptr), tamanho(0) {}

        // Destrutor
        ~Lista() { limpar(); }

        // Adiciona um novo elemento ao final da lista
        void incluir(const T& valor) {
            Elemento* novoElemento = new Elemento(valor);
            if (fim) {
                fim->proximo = novoElemento;
                novoElemento->anterior = fim;
                fim = novoElemento;
            }
            else {
                inicio = fim = novoElemento;
            }
            tamanho++;
        }

        // Remove um elemento da lista
        void remover(const T& valor) {
            Elemento* atual = inicio;
            while (atual && atual->data != valor) {
                atual = atual->proximo;
            }

            if (atual) {
                if (atual == inicio) {
                    inicio = inicio->proximo;
                    if (inicio) inicio->anterior = nullptr;
                }
                else if (atual == fim) {
                    fim = fim->anterior;
                    if (fim) fim->proximo = nullptr;
                }
                else {
                    atual->anterior->proximo = atual->proximo;
                    atual->proximo->anterior = atual->anterior;
                }
                delete atual;
                tamanho--;
            }
        }

        // Remove todos os elementos da lista
        void limpar() {
            Elemento* atual = inicio;
            while (atual) {
                Elemento* proximo = atual->proximo;
                delete atual;
                atual = proximo;
            }
            inicio = fim = nullptr;
            tamanho = 0;
        }

        // Retorna a quantidade de elementos na lista
        size_t getTamanho() const { return tamanho; }

        // Iterator
        Iterator begin() { return Iterator(inicio); }
        Iterator end() { return Iterator(nullptr); }

        Iterator rbegin() { return Iterator(fim); }
        Iterator rend() { return Iterator(nullptr); }
    };
}

