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