from fastapi import FastAPI, Depends
from sqlalchemy.orm import Session
from database import SessionLocal, engine, Base
import crud

Base.metadata.create_all(bind=engine)
app = FastAPI()

def get_db():
    db = SessionLocal()
    try:
        yield db
    finally:
        db.close()

@app.get("/todos")
def read_todos(db: Session = Depends(get_db)):
    return crud.get_todos(db)

@app.post("/todos")
def add_todo(task: str, db: Session = Depends(get_db)):
    return crud.create_todo(db, task)

@app.delete("/todos/{todo_id}")
def remove_todo(todo_id: int, db: Session = Depends(get_db)):
    return crud.delete_todo(db, todo_id)