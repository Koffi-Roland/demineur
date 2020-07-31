#ifndef INTERFACEGRILLE_H
#define INTERFACEGRILLE_H


class InterfaceGrille
{
public:
    InterfaceGrille();
    virtual void terminerAvecEchec() = 0;
    virtual ~ InterfaceGrille();
};

#endif // INTERFACEGRILLE_H
