scores={'math':80, 'english':20, 'programming':100}

for subject, score in scores.items():
    print(subject.ljust(15), str(score).rjust(4), sep=':')