#ifndef GRAPHE_H
#define GRAPHE_H

#include "Sommet.h"
#include "Arete.h"
#include <vector>

class Graphe
{
    public:
        Graphe();
        ~Graphe();

        std::vector<Sommet*> Getsommets() { return m_sommets; }
        int Getordre() { return m_ordre; }
        std::vector<Arete*> Getaretes() { return m_aretes; }

        void Setaretes(std::vector<Arete*> val) { m_aretes = val; }
        void Setsommets(std::vector<Sommet*> val) { m_sommets = val; }
        void Setordre(int val) { m_ordre = val; }

    private:
        std::vector<Sommet*> m_sommets;
        int m_ordre;
        std::vector<Arete*> m_aretes;
};

#endif // GRAPHE_H
