#include <iostream>

using namespace std;

class IType
{
public:
    virtual void FindAvailableMove()    
    {
        cout << "default called" << endl;
    }
};

class ChessPiece
{
private:
    bool team = false;
    int location = 1;
    IType *type;
public:
    ChessPiece()
    {

    }
    ChessPiece(IType *type)
    {
        this->type = type;
    }
    void SetType(IType *type)
    {
        this->type = type;
    }
    void ShowAvailableMove()
    {
        (*type).FindAvailableMove();
    }
};

class King : public IType
{
public:
    void  FindAvailableMove()
    {
        cout << "this is available move for KING" << endl;
    }
};

class Queen : public IType
{
    void FindAvailableMove()
    {
        cout << "this is available move for QUEEN" << endl;
    }
};

class Pawn : public IType
{
    void FindAvailableMove()
    {
        cout << "this is available move for PAWN" << endl;
    }
};

int main()
{
    //show available move for KING
    ChessPiece king(new King());
    //show available move for QUEEN
    ChessPiece queen(new Queen());
    //show available move for PAWN
    ChessPiece pawn(new Pawn());
    
    king.ShowAvailableMove();
    queen.ShowAvailableMove();
    pawn.ShowAvailableMove();
    return 0;
}