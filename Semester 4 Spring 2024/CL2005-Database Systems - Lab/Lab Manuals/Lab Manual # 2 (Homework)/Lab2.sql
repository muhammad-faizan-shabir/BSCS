--1.createDatabase
create database FaizanShabir;

--2.dropDatabase
drop database FaizanShabir;

--3.useDatabase
use FaizanShabir;

--4.createTable
create table Students
(
Name varchar(30),
Age int,
GPA float,
DOB datetime
);

--5.alterTable
alter table Students add Address varchar(50);

--6.alterTable
alter table Students drop column [Address];

--7.primaryKey
create table Students1
(
RollNo int not null primary key,
Name varchar(30),
Age int,
GPA float,
DOB datetime
);

--8.compositePrimaryKey
create table Students2
(
batchNo int,
serialNo int,
Name varchar(30),
Age int,
GPA float,
DOB datetime,
Primary key(batchNo,serialNo)
);

--9.primaryKey
create table Students3
(
RollNo int not null,
Name varchar(30),
Age int,
GPA float,
DOB datetime
);

alter table Students3 add constraint PrimaryKey Primary Key (RollNo);

--10.sp_help
sp_help Students;

--11.sp_help
sp_help Students1;

--12.sp_help
sp_help Students2;

--13.sp_help
sp_help Students3;

--14.foreignKey
CREATE TABLE dbo.Staff_one
(
staffID [int] Primary Key NOT NULL,
staffName [varchar] (50) NULL,
staffRole [varchar] (50) NULL
);

CREATE TABLE dbo.School_one
(
schID [int] Primary Key NOT NULL,
schName [varchar] (50) NULL,
schdeanID [int] FOREIGN KEY References Staff_one(staffID) ON DELETE NO ACTION ON UPDATE NO ACTION NOT NULL
);

--15.foreignKey
CREATE TABLE dbo.Staff_two
(
staffID [int] Primary Key NOT NULL,
staffName [varchar] (50) NULL,
staffRole [varchar] (50) NULL
);

CREATE TABLE dbo.School_two
(
schID [int] Primary Key NOT NULL,
schName [varchar] (50) NULL,
schdeanID [int] NOT NULL
);

Alter table dbo.School_two
Add Constraint FK_School_Staff_two
FOREIGN KEY (schdeanID) References Staff_two(staffID) ON DELETE Cascade ON UPDATE NO ACTION

--16.insert
INSERT INTO [Students1] ([RollNo],[Name],[Age],[GPA],[DOB])
VALUES (13,'Ahmed',20,2.4,'1/1/1990')
GO

--17.insert
INSERT INTO [Students1] ([RollNo],[Name],[GPA])
VALUES (14,'Ahmed',2.4)
GO

--18.select
select * from Students1;






