-- Works for both Oracle and PostgreSQL

Drop table if exists Faculty;

CREATE TABLE Faculty (
FacNo		CHAR(11),
FacFirstName	VARCHAR(30),
FacLastName	VARCHAR(30),
FacCity		VARCHAR(30),
FacState	CHAR(2),
FacDept	CHAR(10),
FacRank		CHAR(4),
FacSalary	DECIMAL(10,2),
FacSupervisor	CHAR(11),
FacHireDate	DATE,
FacZipCode	CHAR(10),
PRIMARY KEY (FacNo) 
);
-- PostgreSQL requires parent faculty rows to be inserted before child parent rows because COMMIT is automatic

INSERT INTO Faculty
	(FacNo, FacFirstName, FacLastName, FacCity, FacState,
	 FacDept, FacRank, FacSalary, FacSupervisor, FacHireDate, FacZipCode)
	 VALUES ('543-21-0987','VICTORIA','EMMANUEL','BOTHELL','WA','MS','PROF',120000.0,NULL,'2008-04-15','98011-2242');

INSERT INTO Faculty
	(FacNo, FacFirstName, FacLastName, FacCity, FacState,
	 FacDept, FacRank, FacSalary, FacSupervisor, FacHireDate, FacZipCode)
	 VALUES ('765-43-2109','NICKI','MACON','BELLEVUE','WA','FIN','PROF',65000.00,NULL,'2009-04-11','98015-9945');

INSERT INTO Faculty
	(FacNo, FacFirstName, FacLastName, FacCity, FacState,
	 FacDept, FacRank, FacSalary, FacSupervisor, FacHireDate, FacZipCode)
	 VALUES ('654-32-1098','LEONARD','FIBON','SEATTLE','WA','MS','ASSC',70000.00,'543-21-0987','2006-05-01','98121-0094');

INSERT INTO Faculty
	(FacNo, FacFirstName, FacLastName, FacCity, FacState,
	 FacDept, FacRank, FacSalary, FacSupervisor, FacHireDate, FacZipCode)
	 VALUES ('098-76-5432','LEONARD','VINCE','SEATTLE','WA','MS','ASST',35000.00,'654-32-1098','2007-04-10','98111-9921');

INSERT INTO Faculty
	(FacNo, FacFirstName, FacLastName, FacCity, FacState,
	 FacDept, FacRank, FacSalary, FacSupervisor, FacHireDate, FacZipCode)
	 VALUES ('876-54-3210','CRISTOPHER','COLAN','SEATTLE','WA','MS','ASST',40000.00,'654-32-1098','2011-03-01','98114-1332');

INSERT INTO Faculty
	(FacNo, FacFirstName, FacLastName, FacCity, FacState,
	 FacDept, FacRank, FacSalary, FacSupervisor, FacHireDate, FacZipCode)
	 VALUES ('987-65-4321','JULIA','MILLS','SEATTLE','WA','FIN','ASSC',75000.00,'765-43-2109','2012-03-15','98114-9954');

