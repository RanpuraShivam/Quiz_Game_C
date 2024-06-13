from flask import Flask, render_template

app = Flask(__name__)

@app.route('/')
def home():
    return render_template('login.html')

@app.route('/signup')
def signup():
    return render_template('signup.html')

@app.route('/quiz')
def quiz():
    return render_template('quiz.html')

if __name__ == '__main__':
    app.run(debug=True)
