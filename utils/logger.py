from datetime import datetime


def log_menu(option):
    with open("project.log", "a") as file:
        now = datetime.now()

        file.write(
            f"{now.strftime('%Y-%m-%d %H:%M:%S')} -> {option}\n"
        )
