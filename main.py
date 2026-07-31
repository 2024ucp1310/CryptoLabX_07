import os
from collections import Counter
from utils.logger import log_menu


def analyze_file():
    path = "datasets"

    files = [f for f in os.listdir(path) if f.endswith(".txt")]

    if not files:
        print("No dataset files found.")
        return

    print("\nAvailable Files")

    for i, file in enumerate(files, 1):
        print(f"{i}. {file}")

    try:
        choice = int(input("Select file: "))
        filename = files[choice - 1]
    except:
        print("Invalid choice")
        return

    filepath = os.path.join(path, filename)

    with open(filepath, "r", encoding="utf-8") as f:
        text = f.read()

    chars = len(text)
    words = len(text.split())
    lines = len(text.splitlines())

    unique = len(set(text))

    letters = Counter(c.lower() for c in text if c.isalpha())

    print("Characters :", chars)
    print("Words      :", words)
    print("Lines      :", lines)
    print("Unique Chars:", unique)

    print("\nLetter Frequency")

    for k in sorted(letters):
        print(k, ":", letters[k])


while True:

    print("1. Encrypt")
    print("2. Decrypt")
    print("3. Attack")
    print("4. Analyze")
    print("5. Exit")

    choice = input("Enter choice: ")

    if choice == "1":
        log_menu("Encrypt")
        print("Coming Soon")

    elif choice == "2":
        log_menu("Decrypt")
        print("Coming Soon")

    elif choice == "3":
        log_menu("Attack")
        print("Coming Soon")

    elif choice == "4":
        log_menu("Analyze")
        analyze_file()

    elif choice == "5":
        log_menu("Exit")
        print("Goodbye!")
        break

    else:
        print("Invalid Choice")
