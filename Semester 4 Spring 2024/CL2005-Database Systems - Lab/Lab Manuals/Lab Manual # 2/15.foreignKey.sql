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
