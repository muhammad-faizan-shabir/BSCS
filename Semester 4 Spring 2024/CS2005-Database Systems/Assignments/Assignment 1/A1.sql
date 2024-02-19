--Q0 Creating database named A1 
create database A1;

--Q1 Creating table named DEPARTMENT
create table DEPARTMENT
(
ID int primary key,
NAME varchar(25) 
);

--Q2P1 Populating the DEPARTMENT table with some data.
insert into DEPARTMENT(ID,NAME)
values (6552,'Finance'),
       (7862,'Human Resource'),
	   (6646,'Marketing'),
	   (8827,'Operations');

--Q2P2 Outputting the inserted data in the DEPARTMENT table.
select * from DEPARTMENT;

--Q3 Creating the table named EMPLOYEE
create table EMPLOYEE
(
ID int primary key,
LAST_NAME varchar(25),
FIRST_NAME varchar(25),
DEPT_ID int
);

--Q4P1 Creating the table named MY_EMPLOYEE
create table MY_EMPLOYEE
(
ID int primary key not null,
LAST_NAME varchar(25),
FIRST_NAME varchar(25),
USERID varchar(8),
SALARY int
);

--Q4P2 Describing MY_EMPLOYEE table to identify the column names.
sp_help MY_EMPLOYEE;

--Q5P1 Populating the MY_EMPLOYEE table with the first row of sample data.
insert into MY_EMPLOYEE
values (1,'Patel','Ralph','rpatel',795);

--Q5P2 Outputting the inserted row in the MY_EMPLOYEE table.
select * from MY_EMPLOYEE;

--Q6 Populating the MY_EMPLOYEE table with the second row of sample data. 
insert into MY_EMPLOYEE(ID,LAST_NAME,FIRST_NAME,USERID,SALARY)
values (2,'Dancs','Betty','bdancs',860);

--Q7 Confirming the addition to the table MY_EMPLOYEE.
select * from MY_EMPLOYEE;

--Q8P1 Changing the last name of employee last_name ‘Dancs’ to ‘Hammad’
update MY_EMPLOYEE
set LAST_NAME='Hammad'
where LAST_NAME='Dancs';

--Q8P2 Confirming the updation done in Q8P1.
select * from MY_EMPLOYEE;

--Q9P1 Changing the salary of all those employees who have a letter‘t’ in their name with salary between 500-2000 to 3000.
update MY_EMPLOYEE
set SALARY=3000
where (LAST_NAME like '%t%' or FIRST_NAME like '%t%') and (SALARY>=500 and SALARY<=2000);

--Q9P2 Confirming the updation done in Q9P1.
select * from MY_EMPLOYEE;

--Q10P1 Deleting an employee who have salary greater than 5000.
delete from MY_EMPLOYEE
where SALARY>5000;

--Q10P2 Confirming the updation done in Q10P1
select * from MY_EMPLOYEE;

--Q11P1 Creating table MYEMP1_6552 and MYDEPT1_6552.
create table MYDEPT1_6552
(
Department_ID int primary key not null,
NAME varchar(25),
Location varchar(15)
); 

create table MYEMP1_6552
(
ID numeric(7,0) not null,
NAME varchar(25),
DEPT_ID int foreign key references MYDEPT1_6552(Department_ID)
on delete cascade
on update cascade
constraint pk primary key(ID)
);

--Q11P2 Confirming that MYDEPT1_6552 table is created
sp_help MYDEPT1_6552

--Q11P3 Confirming that MYEMP1_6552  table is created
sp_help MYEMP1_6552

--Q12P1 Modifying the MYEMP1_6552 table to allow for longer employee names (from 25 characters to 50 characters).
alter table MYEMP1_6552
alter column NAME varchar(50);

--Q12P2 Confirming the modification done in Q12P1
sp_help MYEMP1_6552

--Q13P1 Modifying the MYEMP1_6552 table to allow for employee ID to length 12.
alter table MYEMP1_6552
drop constraint pk;

alter table MYEMP1_6552
alter column ID numeric(12,0) not null;

alter table MYEMP1_6552
add primary key(ID);

--Q13P2 Confirming the modification done in Q13P1
sp_help MYEMP1_6552;

--Q14P1 Populating MYDEPT1_ 6552 with data from the DEPT table.
insert into MYDEPT1_6552(Department_ID,NAME)
select ID,NAME
from DEPARTMENT;

--Q14P2 Confirming the insertion done in Q14P2
select * from MYDEPT1_6552;

--Q15 Inserting a row in MYEMP1_ 6552 with id=6552, name=Faizan Shabir and dept_id = 100 (In both cases 1) inserted 2) not inserted write reason) 
/*
This insert query will not run due to Referential integrity.
The DEPT_ID is a foreign key in MYEMP1_6552 table and it references to the
Department_ID which is a primary key in the MYDEPT1_6552 table.
Since Department_ID=100 does not exist in the MYDEPT1_6552 table so we cannot enter
DEPT_ID=100 in the MYEMP1_6552 table.
*/
insert into MYEMP1_6552(ID,NAME,DEPT_ID)
values (6552,'Faizan Shabir',100);

--Q16 Renaming the MYEMP1_ 6552 table to EMP1_ 6552 and MYDEPT1_6552 to DEPT1_ 6552
exec sp_rename 'MYEMP1_6552','EMP1_6552';
exec sp_rename 'MYDEPT1_6552','DEPT1_6552';

--Q17P1 Dropping the NAME column from the DEPT1_ 6552 table.
alter table DEPT1_6552
drop column NAME;

--Q17P2 Confirming the modification done in Q17P1
sp_help DEPT1_6552;

--Q18P1 Dropping the EMP1_ 6552 table.
drop table EMP1_6552;

--Q18P2 Confirming the modification done in Q18P1
--this query does not run so it is confirmed that EMP1_6552 table is dropped
sp_help EMP1_6552;
