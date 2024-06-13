from quiz import Question
import json

FILE_NAME = "questions.json"

def load_questions_from_file():
    try:
        with open(FILE_NAME, "r") as file:
            questions_data = json.load(file)
            questions = [Question(q["text"], q["correct_answer"]) for q in questions_data]
    except FileNotFoundError:
        print(f"Error: Quiz file '{FILE_NAME}' not found.")
        questions = []
    return questions
