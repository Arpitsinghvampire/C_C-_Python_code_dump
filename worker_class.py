#here we will create a class for the manager class and then  for the next 
#we will create another file that will inherit the class of this module 
class Worker_class():
    def __init__(self ):
        self.name = None
        self.job_role = None
        self.gender = None
        #runs the following functions by default 
        self.get_name_worker()
        self.get_job_role()
        self.get_gender() 
    def get_name_worker(self):
        self.name = input("ENTER THE NAME OF THE WORKER :: ")
    def get_job_role(self):
        self.job_role  = input("ENTER THE ROLE OF THE WORKER ::  ")
    def get_gender(self):
        self.gender = input("ENTER THE GENDER OF THE WORKER ::  ")
    
#now we create another list for getting the another class 

        