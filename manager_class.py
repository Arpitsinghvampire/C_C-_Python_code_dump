#first we import the worker class from the manager class 
import worker_class
#now we have imported the worker class , we now import the class from the worker class
#we inherit the class from the above 
class Manager(worker_class.Worker_class): #this inherits from the above class
    def __init__(self):
       #first we call the init function of the parent class 
       
       worker_class.Worker_class.__init__(self)
       self.get_job_role()
    
       #now we have set the manager position as the job description , now we set the other parameters 
    def get_job_role(self):
        self.job_role = "Manager"

workers_name_job = []

#now we have finished doing and initilizing the parameters of the worker , lets now create a menu function to do the same 
while(True):
    print("ENTER 1 TO ADD A NEW WORKER ")
    print("ENTER 2 TO EXIT ")
    #now when you exit you get to know the previous employers 
     
    choice = int(input("ENTER THE CHOICE YOU WANT TO PERFORM ::  "))
    if choice ==1 :
        print("ENTER 0 TO ADD A ORDINARY WORKER ")
        print("ELSE ENTER 1 TO ADD A MANAGER ")
        choice1 = int(input("ENTER THE TYPE OF THE WORKER :: "))
        if choice1 == 0:
            list1 = []
            worker = worker_class.Worker_class()
            #you will get the workers , we also need to store the 
            list1.append(worker.name)
            list1.append(worker.job_role)
            workers_name_job.append(list1)
        if choice1 == 1:
            list1 = []
            worker1 = Manager()
            list1.append(worker1.name)
            list1.append(worker1.job_role)
            workers_name_job.append(list1)
    else:
        for index , element in enumerate(workers_name_job):
            print("{0}th person name is {1} , role is {2}".format(index+1 ,workers_name_job[index][0] , workers_name_job[index][1]))
        break
            
            
            
            
            
    