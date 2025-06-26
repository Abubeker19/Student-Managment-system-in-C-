def display_all_students(data):
    if not data:
        print("No student records available.")
        return

    print(f"{'ID':<5} {'Name':<20} {'Grade'}")
    print("-" * 35)
    for student in data:
        print(f"{student['id']:<5} {student['name']:<20} {student['grade']}")
