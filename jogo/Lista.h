#ifndef LISTA_H
#define LISTA_H

template <class TL>
class Lista {
private:
    Elemento<TL>* pPrimeiro;
    Elemento<TL>* pUltimo;

public:
    Lista() : pPrimeiro(nullptr), pUltimo(nullptr) {}

    ~Lista() {
        limpar();
    }

    void incluir(TL* obj) {
        Elemento<TL>* novo = new Elemento<TL>(obj);
        if (!pPrimeiro) {
            pPrimeiro = pUltimo = novo;
        } else {
            pUltimo->pProx = novo;
            pUltimo = novo;
        }
    }

    void limpar() {
        Elemento<TL>* atual = pPrimeiro;
        while (atual) {
            Elemento<TL>* temp = atual;
            atual = atual->pProx;
            delete temp->pInfo;
            delete temp;
        }
        pPrimeiro = pUltimo = nullptr;
    }

    Elemento<TL>* getPrimeiro() const { return pPrimeiro; }
    Elemento<TL>* getUltimo() const { return pUltimo; }
};

#endif
