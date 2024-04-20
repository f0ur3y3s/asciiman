from flask import Flask, render_template
from argparser import parse_args

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

if __name__ == "__main__":
    ip, port = parse_args()
    app.run(debug=True, host=ip, port=port)
