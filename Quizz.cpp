#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

struct Question {
    std::string question;
    std::string options[4];
    char correctOption;
};

void printGradientBackground() {
    // Function to print gradient background
    srand(time(NULL));
    std::cout << "\033[48;2;" << (rand() % 256) << ";" << (rand() % 256) << ";" << (rand() % 256) << "m";
}

void printContrastText(const std::string &text) {
    // Function to print text with contrasting color
    std::cout << "\033[38;2;255;255;255m" << text << "\033[0m";
}

void displayRules() {
    // Function to display rules and regulations
    std::cout << "\nRules & Regulations:\n";
    std::cout << "1. You will be asked 5 random questions from the chosen topic.\n";
    std::cout << "2. Choose the correct option by entering the corresponding letter.\n";
    std::cout << "3. You need to answer at least 3 questions correctly to pass.\n";
    std::cout << "4. No negative marking for wrong answers.\n";
    std::cout << "5. Enjoy the quiz!\n";
    std::cout << "6. Good luck!\n\n";
}

Question generateQuestion(int topic) {
    // Function to generate random questions
    srand(time(NULL));
    Question questions[5][10] = {
        // Geography
        {
            {"What is the capital of France?", {"a. London", "b. Paris", "c. Rome", "d. Berlin"}, 'b'},
            {"Which continent is the largest by land area?", {"a. Asia", "b. Africa", "c. North America", "d. Europe"}, 'a'},
            {"What is the longest river in the world?", {"a. Nile", "b. Amazon", "c. Mississippi", "d. Yangtze"}, 'b'},
            {"Which country is known as the 'Land of the Rising Sun'?", {"a. China", "b. Japan", "c. India", "d. Australia"}, 'b'},
            {"Which ocean is the largest?", {"a. Atlantic Ocean", "b. Indian Ocean", "c. Pacific Ocean", "d. Arctic Ocean"}, 'c'},
            {"Which country is known as the 'Roof of the World'?", {"a. Nepal", "b. Bhutan", "c. China", "d. India"}, 'a'},
            {"What is the currency of Japan?", {"a. Yen", "b. Yuan", "c. Rupee", "d. Euro"}, 'a'},
            {"What is the world's smallest country?", {"a. Monaco", "b. Vatican City", "c. Liechtenstein", "d. San Marino"}, 'b'},
            {"What is the largest desert in the world?", {"a. Sahara Desert", "b. Gobi Desert", "c. Arabian Desert", "d. Antarctic Desert"}, 'a'},
            {"Which mountain range stretches across six countries?", {"a. Andes", "b. Himalayas", "c. Alps", "d. Rocky Mountains"}, 'a'}
        },
        // History
        {
            {"Who was the first President of the United States?", {"a. George Washington", "b. Thomas Jefferson", "c. Abraham Lincoln", "d. John F. Kennedy"}, 'a'},
            {"Which year did World War I begin?", {"a. 1914", "b. 1918", "c. 1939", "d. 1945"}, 'a'},
            {"In which city was the Declaration of Independence signed?", {"a. Boston", "b. New York", "c. Philadelphia", "d. Washington D.C."}, 'c'},
            {"Who was the first female Prime Minister of the United Kingdom?", {"a. Margaret Thatcher", "b. Angela Merkel", "c. Theresa May", "d. Indira Gandhi"}, 'a'},
            {"When did the Berlin Wall fall?", {"a. 1985", "b. 1989", "c. 1991", "d. 1995"}, 'b'},
            {"Who was the first Emperor of Rome?", {"a. Julius Caesar", "b. Augustus", "c. Nero", "d. Constantine"}, 'b'},
            {"Which war was fought between the North and South regions of the United States?", {"a. Civil War", "b. Revolutionary War", "c. World War II", "d. Vietnam War"}, 'a'},
            {"Which ancient civilization built the Great Wall of China?", {"a. Roman Empire", "b. Persian Empire", "c. Chinese Empire", "d. Mongol Empire"}, 'c'},
            {"Who was the first female Pharaoh of ancient Egypt?", {"a. Cleopatra", "b. Nefertiti", "c. Hatshepsut", "d. Ankhesenamun"}, 'c'},
            {"Who was the leader of the Indian independence movement against British rule?", {"a. Mahatma Gandhi", "b. Jawaharlal Nehru", "c. Subhash Chandra Bose", "d. Bhagat Singh"}, 'a'}
        },
        // Technology
        {
            {"Who invented the World Wide Web?", {"a. Bill Gates", "b. Tim Berners-Lee", "c. Steve Jobs", "d. Mark Zuckerberg"}, 'b'},
            {"What does CPU stand for?", {"a. Central Processing Unit", "b. Computer Power Unit", "c. Control Processing Unit", "d. Central Power Unit"}, 'a'},
            {"Which company developed the Android operating system?", {"a. Google", "b. Microsoft", "c. Apple", "d. Samsung"}, 'a'},
            {"What is the full form of HTML?", {"a. Hyperlink Text Markup Language", "b. Hyper Text Markup Language", "c. High Tech Markup Language", "d. Hyper Transfer Markup Language"}, 'b'},
            {"What is the main purpose of a firewall in a computer network?", {"a. To enhance internet speed", "b. To prevent unauthorized access", "c. To improve computer performance", "d. To create backups"}, 'b'},
            {"Which programming language is known as the 'father of all programming languages'?", {"a. Java", "b. C", "c. Python", "d. Assembly"}, 'b'},
            {"Who founded Apple Inc.?", {"a. Steve Jobs", "b. Bill Gates", "c. Steve Wozniak", "d. Mark Zuckerberg"}, 'c'},
            {"What does USB stand for?", {"a. Universal Serial Bus", "b. United States of America", "c. Uniform System of Banking", "d. Ultra Speed Bandwidth"}, 'a'},
            {"Which company introduced the first commercial microprocessor?", {"a. Intel", "b. IBM", "c. Apple", "d. Microsoft"}, 'a'},
            {"What is the main function of RAM in a computer?", {"a. Permanent storage", "b. Temporary storage", "c. Processing data", "d. Displaying output"}, 'b'}
        },
        // Mathematics
        {
            {"What is the value of pi (π) to two decimal places?", {"a. 3.14", "b. 3.16", "c. 3.18", "d. 3.12"}, 'a'},
            {"What is the square root of 144?", {"a. 12", "b. 14", "c. 16", "d. 18"}, 'a'},
            {"What is the value of 'e' (Euler's Number)?", {"a. 2.71", "b. 3.14", "c. 2.50", "d. 3.00"}, 'a'},
            {"What is the smallest prime number?", {"a. 0", "b. 1", "c. 2", "d. 3"}, 'c'},
            {"What is the sum of angles in a triangle?", {"a. 90 degrees", "b. 180 degrees", "c. 270 degrees", "d. 360 degrees"}, 'b'},
            {"What is the value of 'pi' correct to 3 decimal places?", {"a. 3.141", "b. 3.142", "c. 3.143", "d. 3.144"}, 'a'},
            {"What is the largest prime number less than 100?", {"a. 97", "b. 99", "c. 101", "d. 103"}, 'a'},
            {"What is the value of 'log10(1000)'?", {"a. 1", "b. 2", "c. 3", "d. 4"}, 'b'},
            {"What is the value of 'sin(90 degrees)'?", {"a. 0", "b. 1", "c. -1", "d. Undefined"}, 'b'},
            {"What is the value of 'tan(45 degrees)'?", {"a. 0", "b. 1", "c. -1", "d. Undefined"}, 'b'}
        },
        // Indian Politics
        {
            {"Who is known as the Iron Man of India?", {"a. Jawaharlal Nehru", "b. Sardar Vallabhbhai Patel", "c. Mahatma Gandhi", "d. Subhash Chandra Bose"}, 'b'},
            {"When was the Indian Constitution adopted?", {"a. 1947", "b. 1950", "c. 1955", "d. 1960"}, 'b'},
            {"Who was the first woman Prime Minister of India?", {"a. Indira Gandhi", "b. Sonia Gandhi", "c. Mayawati", "d. Mamata Banerjee"}, 'a'},
            {"Who is the current Prime Minister of India?", {"a. Narendra Modi", "b. Manmohan Singh", "c. Rajnath Singh", "d. Amit Shah"}, 'a'},
            {"Which political party was founded by Bal Gangadhar Tilak?", {"a. Indian National Congress", "b. Rashtriya Swayamsevak Sangh", "c. Bharatiya Janata Party", "d. All India Trinamool Congress"}, 'a'},
            {"Who was the first President of India?", {"a. Rajendra Prasad", "b. Jawaharlal Nehru", "c. Dr. B.R. Ambedkar", "d. Sardar Vallabhbhai Patel"}, 'a'},
            {"Who assassinated Mahatma Gandhi?", {"a. Nathuram Godse", "b. Bhagat Singh", "c. Udham Singh", "d. Chandrashekhar Azad"}, 'a'},
            {"Who drafted the Indian Constitution?", {"a. Dr. B.R. Ambedkar", "b. Jawaharlal Nehru", "c. Mahatma Gandhi", "d. Sardar Vallabhbhai Patel"}, 'a'},
            {"Which Indian state has the highest number of Lok Sabha seats?", {"a. Maharashtra", "b. Uttar Pradesh", "c. West Bengal", "d. Bihar"}, 'b'},
            {"Who was the first Chief Minister of independent India?", {"a. Jawaharlal Nehru", "b. Sardar Vallabhbhai Patel", "c. C. Rajagopalachari", "d. B.R. Ambedkar"}, 'c'}
        }
    };
    
    // Shuffle the questions for the given topic
    std::random_shuffle(std::begin(questions[topic]), std::end(questions[topic]));

    return questions[topic][0]; // Return the first question after shuffling
}

void playQuiz() {
    // Function to play quiz
    std::string playerName;
    std::cout << "Enter your name: ";
    std::getline(std::cin, playerName);
    printGradientBackground();
    std::cout << "\nWelcome, ";
    printContrastText(playerName);
    std::cout << "!\n\n";

    displayRules();

    std::cout << "Choose a topic to start the quiz:\n";
    std::cout << "1. Geography\n2. History\n3. Technology\n4. Mathematics\n5. Indian Politics\n\n";

    int choice;
    std::cout << "Enter your choice (1-5): ";
    std::cin >> choice;
    while (choice < 1 || choice > 5) {
        std::cout << "Invalid choice! Please enter a number between 1 and 5: ";
        std::cin >> choice;
    }
    int topic = choice - 1;

    Question q;
    int correctAnswers = 0;
    for (int i = 0; i < 5; ++i) {
        q = generateQuestion(topic);
        std::cout << "\nQuestion " << (i + 1) << ": " << q.question << "\n";
        for (int j = 0; j < 4; ++j) {
            std::cout << q.options[j] << "\n";
        }
        char answer;
        std::cout << "\nEnter your answer (a, b, c, or d): ";
        std::cin >> answer;
        if (tolower(answer) == q.correctOption) {
            std::cout << "Correct!\n";
            ++correctAnswers;
        } else {
            std::cout << "Incorrect. The correct answer is: " << q.options[q.correctOption - 'a'] << "\n";
        }
    }

    std::cout << "\n\n";
    if (correctAnswers >= 3) {
        std::cout << "Congratulations, " << playerName << "! You passed the quiz with " << correctAnswers << " correct answers out of 5.\n";
    } else {
        std::cout << "Sorry, " << playerName << ". You failed the quiz with " << correctAnswers << " correct answers out of 5. Better luck next time!\n";
    }
}

int main() {
    printGradientBackground(); // Print background color before anything else
    playQuiz();
    return 0;
}