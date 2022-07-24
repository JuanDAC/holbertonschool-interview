
# 0x02. Minimum Operations
## Details
      By Carrie Ybay, Software Engineer at Holberton School          Weight: 1          Manual review behavior: Reviewed students        ### Admin corner
[Cohort adjustments](https://intranet.hbtn.io/projects/1215#) 
[Preview manual QA review sheet](https://intranet.hbtn.io/corrections/preview_correct?project_id=1215) 
×#### Cohort adjustment for Project - 1215
[New](https://intranet.hbtn.io/batch_projects/new?project_id=1215) 
 /.modal-content  /.modal-dialog  /.modal * [Metadata](https://intranet.hbtn.io/projects/1215#admin-corner-metadata) 

* [Started by cohorts](https://intranet.hbtn.io/projects/1215#admin-corner-batches) 

* [Peer learning days](https://intranet.hbtn.io/projects/1215#admin-corner-plds) 

* [Resource links](https://intranet.hbtn.io/projects/1215#admin-corner-resources) 

* [Reminders](https://intranet.hbtn.io/projects/1215#admin-corner-reminders) 

* [Dependencies](https://intranet.hbtn.io/projects/1215#admin-corner-dependencies) 

*       Main code language: python    
*       Project will be corrected at 00:00 (school location time)    
* Checker was released at 04-27-2022 12:00 AM
*     Track:   
*     Block: [Interview Preparation](https://intranet.hbtn.io/blocks/134) 

* Online
*     Must be corrected: true  
*       Weight: 1    
*     Position: 3  
*     Days offset: 3  
*     Duration: 4 days  
*     Work hours: 32 hours  
*     Project to be done in teams of 1 people  
*     Team distribution algo:   
*     Excluded from check contributors: false    

[BOG-0621](https://intranet.hbtn.io/batches/113) 
        ([from 2022-04-25 to 2022-04-29](https://intranet.hbtn.io/batch_planning_items/24834) 
)      [MDE-0621](https://intranet.hbtn.io/batches/116) 
        ([from 2022-04-25 to 2022-04-29](https://intranet.hbtn.io/batch_planning_items/24847) 
)      [CLO-0621](https://intranet.hbtn.io/batches/109) 
        ([from 2022-04-25 to 2022-04-29](https://intranet.hbtn.io/batch_planning_items/24860) 
)      [BOG-0621](https://intranet.hbtn.io/batches/113) 
        ([from 2022-04-29 to 2022-04-30](https://intranet.hbtn.io/batch_peer_learning_day_items/6539) 
)      [MDE-0621](https://intranet.hbtn.io/batches/116) 
        ([from 2022-04-29 to 2022-04-30](https://intranet.hbtn.io/batch_peer_learning_day_items/6543) 
)      [CLO-0621](https://intranet.hbtn.io/batches/109) 
        ([from 2022-04-29 to 2022-04-30](https://intranet.hbtn.io/batch_peer_learning_day_items/6547) 
)      [BAQ-0621](https://intranet.hbtn.io/batches/111) 
        ([from 2022-04-29 to 2022-04-30](https://intranet.hbtn.io/batch_peer_learning_day_items/6555) 
)      [UIO-0621](https://intranet.hbtn.io/batches/129) 
        ([from 2022-04-29 to 2022-04-30](https://intranet.hbtn.io/batch_peer_learning_day_items/6565) 
)      All clear. Nothing to see here.All clear. Nothing to see here.##### Required projects
All clear. Nothing to see here.##### Dependent projects
All clear. Nothing to see here.## Requirements
### General
* Allowed editors:  ` vi ` ,  ` vim ` ,  ` emacs ` 
* All your files will be interpreted/compiled on Ubuntu 14.04 LTS using  ` python3 `  (version 3.4.3)
* All your files should end with a new line
* The first line of all your files should be exactly  ` #!/usr/bin/python3 ` 
* A  ` README.md `  file, at the root of the folder of the project, is mandatory
* Your code should be documented
* Your code should use the  ` PEP 8 `  style (version 1.7.x)
* All your files must be executable
## Tasks
### 0. Minimum Operations
          Level: -1                    Auto review           Progress vs Score  Task Body In a text file, there is a single character   ` H `  . Your text editor can execute only two operations in this file:   ` Copy All `   and   ` Paste `  . Given a number   ` n `  , write a method that calculates the fewest number of operations needed to result in exactly   ` n `   ` H `   characters in the file.
* Prototype:  ` def minOperations(n) ` 
* Returns an integer
* If  ` n `  is impossible to achieve, return  ` 0 ` 
Example:
 ` n = 9 ` 
 ` H `   =>   ` Copy All `   =>   ` Paste `   =>   ` HH `   =>   ` Paste `   =>  ` HHH `   =>   ` Copy All `   =>   ` Paste `   =>   ` HHHHHH `   =>   ` Paste `   =>   ` HHHHHHHHH ` 
Number of operations:   ` 6 ` 
```bash
carrie@ubuntu:~/0x02-minoperations$ cat 0-main.py
#!/usr/bin/python3
"""
Main file for testing
"""

minOperations = __import__('0-minoperations').minOperations

n = 4
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 12
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

carrie@ubuntu:~/0x02-minoperations$

```
```bash
carrie@ubuntu:~/0x02-minoperations$ ./0-main.py
Min number of operations to reach 4 characters: 4
Min number of operations to reach 12 characters: 7
carrie@ubuntu:~/0x02-minoperations$

```
 Task URLs  Github information Repo:
* GitHub repository:  ` holbertonschool-interview ` 
* Directory:  ` 0x02-minimum_operations ` 
* File:  ` 0-minoperations.py ` 
* Code language:                 ` python `  (project based)            
 Self-paced manual review  Panel footer - Controls 
