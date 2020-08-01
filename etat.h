#ifndef ETAT_H
#define ETAT_H

class Case;

class Etat
{
protected:
    Case *_case;
public:
    Etat();
    void setCase(Case *_case);
    virtual void initialiser() = 0;
    virtual void devoiler() = 0;
    virtual void marquer() = 0;
    virtual void desactiver() = 0;
    virtual int getEtat() = 0;
    virtual ~Etat();
};

#endif // ETAT_H
