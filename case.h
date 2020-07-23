#ifndef CASE_H
#define CASE_H


class Case
{
private:
    int x;
    int y;
public:
    Case();
    Case(int,int);
    ~Case(void);
    int getVoisines();
    int getNombreMine();
    void devoiler();
    void marquer();
};

#endif // CASE_H
