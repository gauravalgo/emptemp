#include <iostream>
class AbstractExpr{
  public :
    virtual double eval() const= 0;
};
class TerminalExpr :public AbstractExpr{
  
};
class NonTerminalExpr : public AbstractExpr{

};
class Literal: public TerminalExpr {
  public:
    Literal(double v): _val(v) {}
    double eval() const { return _val; }
  private:
    const double _val;
};
class Variable: public TerminalExpr{
  public:
    Variable(double v): _val(v){}
    double eval() const { return _val; }
  private:
    double& _val;
};
class BinaryExpr : public NonTerminalExpr{
public:
  BinaryExpr(const AbstractExpr *e1,const AbstractExpr* e2):_expr1(e1),_expr2(e2){}
  virtual ~BinaryExpr()
  {
    delete const_cast<AbstractExpr *>(_expr1);
    delete const_cast<AbstractExpr *>(_expr2);
  }
  const AbstractExpr *_expr1;
  const AbstractExpr *_expr2;
};
class Sum : public BinaryExpr {
  public:
    Sum(const AbstractExpr *e1, const AbstractExpr *e2):BinaryExpr(e1, e2){}
    double eval() const{
      return _expr1->eval() + _expr2->eval();
    }
};
class Product : public BinaryExpr {
  public:
    Product(const AbstractExpr *e1, const AbstractExpr *e2):BinaryExpr(e1, e2){}
    double eval() const{
      return _expr1->eval() + _expr2->eval();
    }
};

int main(int argc, char *argv[])
{
  double x;
  Product expr(new Sum(new Variable(x),new Literal(2)),new Literal(3));
  std::cout<< expr.eval();
}
