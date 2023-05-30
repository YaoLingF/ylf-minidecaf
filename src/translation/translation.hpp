/*****************************************************
 *  Definition of the two AST translation passes.
 *
 *  Keltin Leung 
 */

#ifndef __MIND_TRANSLATION__INTERNAL__
#define __MIND_TRANSLATION__INTERNAL__

#include "3rdparty/vector.hpp"
#include "ast/visitor.hpp"
#include "define.hpp"

// we assume the target machine is a 32-bit machine for simplicity.
#define POINTER_SIZE 4
#define WORD_SIZE 4

namespace mind {

class Translation : public ast::Visitor {
  public:
    Translation(tac::TransHelper *);

    virtual void visit(ast::Program *);
    virtual void visit(ast::FuncDefn *);
    virtual void visit(ast::AssignExpr *);
    virtual void visit(ast::CompStmt *);
    virtual void visit(ast::ExprStmt *);
    virtual void visit(ast::IfStmt *);
    virtual void visit(ast::ReturnStmt *);
    virtual void visit(ast::AddExpr *);
    virtual void visit(ast::SubExpr *);//减
    virtual void visit(ast::MulExpr *);//乘
    virtual void visit(ast::DivExpr *);//除
    virtual void visit(ast::ModExpr *);//模
    
    virtual void visit(ast::LesExpr *);//step4
    virtual void visit(ast::GrtExpr *);
    virtual void visit(ast::LeqExpr *);
    virtual void visit(ast::GeqExpr *);
    virtual void visit(ast::EquExpr *);
    virtual void visit(ast::NeqExpr *);
    virtual void visit(ast::AndExpr *);
    virtual void visit(ast::OrExpr *);
    
    virtual void visit(ast::IntConst *);
    virtual void visit(ast::NegExpr *);
    virtual void visit(ast::NotExpr *);//逻辑
    virtual void visit(ast::BitNotExpr *);//按位
    virtual void visit(ast::LvalueExpr *);
    virtual void visit(ast::VarRef *);
    virtual void visit(ast::VarDecl *);
    virtual void visit(ast::WhileStmt *);
    virtual void visit(ast::BreakStmt *);
    
    virtual void visit(ast::IfExpr *);//step6

    virtual ~Translation() {}

  private:
    tac::TransHelper *tr;
    tac::Label current_break_label;
    // TODO: label for continue
};
} // namespace mind

#endif // __MIND_TRANSLATION__INTERNAL__
