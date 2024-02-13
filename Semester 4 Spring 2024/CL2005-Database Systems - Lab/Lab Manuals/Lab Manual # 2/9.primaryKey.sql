create table Students3
(
RollNo int not null,
Name varchar(30),
Age int,
GPA float,
DOB datetime
);

alter table Students3 add constraint PrimaryKey Primary Key (RollNo);