from abc import ABC, abstractmethod
class Student():
    
    def __init__(self, roll, name, prog_name) -> None:
        self.rollnum = roll
        self.name = name
        self.prog_name = prog_name

    def Intro(self):
        print(f"Name : {self.name} \nRoll : {self.rollnum} \nProgram : {self.prog_name} \n")    

    def SetFellowStatus(self, fellowstatus=None):
        self.fellowstatus = fellowstatus

    def SetCourseStatus(self, Coursestatus=None):
        self.Coursestatus = Coursestatus

    def GetFellowStatus(self):
        self.fellowstatus.Isfellow()

    def GetCourseStatus(self):
        self.Coursestatus.Courselevel()   

class Fellow(ABC):  

    @abstractmethod
    def Isfellow(self):
        pass

class FellowYes(Fellow):
    def Isfellow(self):
        print("I recieve fellowship \n")

class FellowNo(Fellow):
    def Isfellow(self):
        print("I don't recieve fellowship \n")

class Courses(ABC):
    @abstractmethod
    def Courselevel(self):
        pass

class CourseDiff(Courses):
    def Courselevel(self):
        print("I Do 700 lvl courses \n")

class CourseEasy(Courses):
    def Courselevel(self):
        print("I don't do 700 lvl courses \n")   

class Phd(Student):
    pass    

class PGD(Student):
    pass

class Masters(Student):
    pass

class UG(Student):
    pass

if __name__ == "__main__":

    stud1 = Masters("124", "shubham", "Mtech")
    stud2 = Phd("095", "ayush", "Phd")
    stud3 = UG("122", "pratik", "Btech")
    stud4 = PGD("119", "nikhilesh", "Diploma")             

    stud1.SetFellowStatus(FellowNo())
    stud1.SetCourseStatus(CourseDiff())

    stud2.SetFellowStatus(FellowYes())
    stud2.SetCourseStatus(CourseDiff())

    stud3.SetFellowStatus(FellowNo())
    stud3.SetCourseStatus(CourseEasy())

    stud4.SetFellowStatus(FellowNo())
    stud4.SetCourseStatus(CourseDiff())


    stud1.Intro()
    stud1.GetFellowStatus()
    stud1.GetCourseStatus()
    print("--------------------------------------")

    stud2.Intro()
    stud2.GetFellowStatus()
    stud2.GetCourseStatus()
    print("--------------------------------------")

    stud3.Intro()
    stud3.GetFellowStatus()
    stud3.GetCourseStatus()
    print("--------------------------------------")
    
    stud4.Intro()
    stud4.GetFellowStatus()
    stud4.GetCourseStatus()

        