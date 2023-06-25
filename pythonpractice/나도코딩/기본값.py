# def profile(name, age=17, main_lang="python"):
#     print("이름: {0}\t나이: {1}\t주 사용 언어: {2}".format(name, age, main_lang))

# profile("유재석")

def profile(name, age, *language):
    print("name : {}\tage : {}\tlanguage : ".format(name, age), end="")
    for lang in language:
        print("{}".format(lang), end=" ")
    print()

profile("solsol", 21, "C", "Python")
profile("rwa", 19, "javascript", "html", "CSS")