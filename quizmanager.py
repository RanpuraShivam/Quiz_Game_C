from quiz import Question
from fileio import load_questions_from_file

class QuizManager:
    def __init__(self):
        self.questions = load_questions_from_file()
        self.current_question_index = 0
        self.score = 0

    def get_next_question(self):
        if self.current_question_index < len(self.questions):
            question = self.questions[self.current_question_index]
            self.current_question_index += 1
            return question
        else:
            return None

    def is_quiz_complete(self):
        return self.current_question_index == len(self.questions)

    def check_answer(self, user_answer):
        current_question = self.questions[self.current_question_index - 1]
        if user_answer.lower() == current_question.correct_answer.lower():
            print("Correct!\n")
            self.score += 1
        else:
            print(f"Incorrect. The correct answer is: {current_question.correct_answer}\n")

    def get_score(self):
        return self.score

    def get_total_questions(self):
        return len(self.questions)
