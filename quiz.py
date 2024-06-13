class Question:
    def __init__(self, text, correct_answer):
        self.text = text
        self.correct_answer = correct_answer

    def __str__(self):
        return self.text
