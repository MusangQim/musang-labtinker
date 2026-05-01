#!/usr/bin/env python3
import datetime
import sys

new_task = {
    "id": len(tasks) + 1,
    "description": sys.argv[2],
    "status": "todo",
    "createdAt": datetime.datetime.now(),
    "updatedAt": datetime.datetime.now()
}


def handle_argument() -> None:
    if len(sys.argv) > 1:
        action = sys.argv[1]
        if action == "add":
            print("Add command detected")
        elif action == "update":
            print("Update command detected")
        elif action == "list":
            print("List command detected")
        elif action == "delete":
            print("Delete command detected")
        else:
            print("No command detected")
    else:
        print("No argument given")


def main() -> None:
    print("=== Task Tracker ===")
    handle_argument()


if __name__ == "__main__":
    main()


#for input_list in range(1, len(sys.argv)):
        #    print(f"Task added: {sys.argv[input_list]}")
