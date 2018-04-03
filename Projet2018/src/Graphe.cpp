#include "Graphe.h"

Graphe::Graphe(std::string nom_fichier)
{
    int cd_x, cd_y, num, poids;
//    Sommet* s;
    std::string nom_img;

    std::ifstream fichier(nom_fichier, std::ios::in);
    if (!fichier)
    {
        std::cout << nom_fichier << " ne peut pas etre ouvert!" << std::endl;
        return;
    }
    else
    {
        fichier >> m_ordre;
        for (int i(0); i<m_ordre; ++i)
        {

            fichier >> nom_img;
            fichier >> cd_x >> cd_y >> num >> poids;

//            s = new Sommet()
            ajouterSommet(new Sommet(cd_x, cd_y, num, poids, nom_img));
        }
    }
}

Graphe::~Graphe()
{
    //dtor
}

void Graphe::affichage(BITMAP* buffer, BITMAP* barre)
{
    for (unsigned int i(0); i<Getsommets().size(); ++i)
    {
        blit(getSommet(i)->GetImg(), buffer, 0, 0, (getSommet(i))->GetCd_x(), (getSommet(i))->GetCd_y(), getSommet(i)->GetImg()->w, getSommet(i)->GetImg()->h);
    }

    blit(barre, buffer,0,0,0,600 - barre->h, barre->w, barre->h);

    textprintf_ex(buffer, font, 400, 23, makecol(255,255,0), -1,"%d", mouse_x);
    textprintf_ex(buffer, font, 440, 23, makecol(255,255,0), -1,"%d", mouse_y);

    blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    clear_bitmap(buffer);

}

void Graphe::outils(BITMAP* buffer)
{
//    rectfill(buffer, )
}

void Graphe::ajouterArete(BITMAP* buffer)
{
    Arete* a;
    Sommet* s;

    a= new Arete;
    s= new Sommet;

    std::vector<Arete*> tmp;

    while(s->getNomImg() == "")
    {
        for (unsigned int i(Getsommets().size() - 1); i > 0; --i)
        {
            if(is_mouse(Getsommets()[i]->GetCd_x(), Getsommets()[i]->GetImg()->w, Getsommets()[i]->GetCd_y(), Getsommets()[i]->GetImg()->h))
            {
                if(mouse_b&1)
                {
                    s = Getsommets()[i];
                    a->Setdepart(s);
                }
            }
        }
    }

    rectfill(buffer, a->Getdepart()->GetCd_x()-2, a->Getdepart()->GetCd_y()-2, a->Getdepart()->GetImg()->w +a->Getdepart()->GetCd_x()+1,a->Getdepart()->GetImg()->h + a->Getdepart()->GetCd_y()+1, makecol(255,0,0));

    s= new Sommet;

    while(s->getNomImg() == "")
    {
        for (unsigned int i(0); i<Getsommets().size(); ++i)
        {
            if(is_mouse(Getsommets()[i]->GetCd_x(), Getsommets()[i]->GetImg()->w, Getsommets()[i]->GetCd_y(), Getsommets()[i]->GetImg()->h))
            {
                if(mouse_b&1)
                {
                    s = Getsommets()[i];
                    a->Setarrive(s);
                }
            }
        }
    }

    tmp.push_back(a);

    Setaretes(tmp);
}

void Graphe::update(BITMAP* buffer, BITMAP* barre)
{
    for(int i(Getsommets().size()-1); i >= 0 ; --i)
    {
        if(is_mouse(Getsommets()[i]->GetCd_x(), Getsommets()[i]->GetImg()->w, Getsommets()[i]->GetCd_y(), Getsommets()[i]->GetImg()->h))
        {

            if(mouse_b&1)
            {

                while(mouse_b&1)
                {
                    rectfill(buffer, Getsommets()[i]->GetCd_x()-2, Getsommets()[i]->GetCd_y()-2, Getsommets()[i]->GetImg()->w +Getsommets()[i]->GetCd_x()+1,Getsommets()[i]->GetImg()->h+Getsommets()[i]->GetCd_y()+1, makecol(0,255,0));

                    Getsommets()[i]->SetCd_x(mouse_x-Getsommets()[i]->GetImg()->w/2);
                    Getsommets()[i]->SetCd_y(mouse_y-Getsommets()[i]->GetImg()->h/2);

                    affichage(buffer, barre);
                }
            }
        }
    }
}

bool Graphe::is_mouse(int x, int weight, int y, int height)
{
    return     mouse_x >= x && mouse_x <= x + weight  &&  mouse_y >= y && mouse_y <= y + height;
}
