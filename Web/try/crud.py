from sqlalchemy.orm import Session
from models import Todo

def get_todos(db: Session):
    return db.query(Todo).all()

def create_todo(db: Session, task: str):
    todo = Todo(task=task)
    db.add(todo)
    db.commit()
    db.refresh(todo)
    return todo

def delete_todo(db: Session, todo_id: int):
    todo = db.query(Todo).filter(Todo.id == todo_id).first()
    if todo:
        db.delete(todo)
        db.commit()
    return todo