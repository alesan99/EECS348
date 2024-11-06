-- Works for both Oracle and PostgreSQL
Drop TABLE IF EXISTS Student;

CREATE TABLE Student
( StdNo 	    CHAR(11),
  StdFirstName  VARCHAR(50),
  StdLastName   VARCHAR(50),
  StdCity	    VARCHAR(50),
  StdState	    CHAR(2),
  StdZip	    CHAR(10),
  StdMajor	    CHAR(6),
  StdClass	    CHAR(6),
  StdGPA	    DECIMAL(3,2) DEFAULT 0,	
  PRIMARY KEY (StdNo));	

-- INSERT statements to populate the table

INSERT INTO Student
	(StdNo, StdFirstName, StdLastName, StdCity,
	 StdState, StdMajor, StdClass, StdGPA, StdZip)
	VALUES ('123-45-6789','HOMER','WELLS','SEATTLE','WA','IS','FR',3.00,'98121-1111');


INSERT INTO Student
	(StdNo, StdFirstName, StdLastName, StdCity,
	 StdState, StdMajor, StdClass, StdGPA, StdZip)
	VALUES ('124-56-7890','BOB','NORBERT','BOTHELL','WA','FIN','JR',2.70,'98011-2121');

INSERT INTO Student
	(StdNo, StdFirstName, StdLastName, StdCity,
	 StdState, StdMajor, StdClass, StdGPA, StdZip)
	VALUES ('234-56-7890','CANDY','KENDALL','TACOMA','WA','ACCT','JR',3.50,'99042-3321');

INSERT INTO Student
	(StdNo, StdFirstName, StdLastName, StdCity,
	 StdState, StdMajor, StdClass, StdGPA, StdZip)
	VALUES ('345-67-8901','WALLY','KENDALL','SEATTLE','WA','IS','SR',2.80,'98123-1141');

INSERT INTO Student
	(StdNo, StdFirstName, StdLastName, StdCity,
	 StdState, StdMajor, StdClass, StdGPA, StdZip)
	VALUES ('456-78-9012','JOE','ESTRADA','SEATTLE','WA','FIN','SR',3.20,'98121-2333');

INSERT INTO Student
	(StdNo, StdFirstName, StdLastName, StdCity,
	 StdState, StdMajor, StdClass, StdGPA, StdZip)
	VALUES ('567-89-0123','MARIAH','DODGE','SEATTLE','WA','IS','JR',3.60,'98114-0021');

INSERT INTO Student
	(StdNo, StdFirstName, StdLastName, StdCity,
	 StdState, StdMajor, StdClass, StdGPA, StdZip)
	VALUES ('678-90-1234','TESS','DODGE','REDMOND','WA','ACCT','SO',3.30,'98116-2344');

INSERT INTO Student
	(StdNo, StdFirstName, StdLastName, StdCity,
	 StdState, StdMajor, StdClass, StdGPA, StdZip)
	VALUES ('789-01-2345','ROBERTO','MORALES','SEATTLE','WA','FIN','JR',2.50,'98121-2212');

INSERT INTO Student
	(StdNo, StdFirstName, StdLastName, StdCity,
	 StdState, StdMajor, StdClass, StdGPA, StdZip)
	VALUES ('876-54-3210','CRISTOPHER','COLAN','SEATTLE','WA','IS','SR',4.00,'98114-1332');

INSERT INTO Student
	(StdNo, StdFirstName, StdLastName, StdCity,
	 StdState, StdMajor, StdClass, StdGPA, StdZip)
	VALUES ('890-12-3456','LUKE','BRAZZI','SEATTLE','WA','IS','SR',2.20,'98116-0021');

INSERT INTO Student
	(StdNo, StdFirstName, StdLastName, StdCity,
	 StdState, StdMajor, StdClass, StdGPA, StdZip)
	VALUES ('901-23-4567','WILLIAM','PILGRIM','BOTHELL','WA','IS','SO',3.80,'98113-1885');

