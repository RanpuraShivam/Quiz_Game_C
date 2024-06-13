from quizmanager import QuizManager

def main():
    quiz_manager = QuizManager()

    print("Welcome to the Python Quiz!")
    print("Answer the following questions:\n")

    while not quiz_manager.is_quiz_complete():
        question = quiz_manager.get_next_question()
        user_answer = input(f"{question}\nYour answer: ")
        quiz_manager.check_answer(user_answer)

    print("\nQuiz Complete!")
    print(f"Your Score: {quiz_manager.get_score()}/{quiz_manager.get_total_questions()}")

if __name__ == "__main__":
    main()
