-- Works for both Oracle and PostgreSQL

Drop table if exists Offering;

CREATE TABLE Offering (
OfferNo INTEGER,
CourseNo CHAR(6),
OffTerm CHAR(6),
OffYear INTEGER,
OffLocation VARCHAR(30),
OffTime VARCHAR(10),
FacNo CHAR(11),
OffDays CHAR(6) DEFAULT 'MW',
PRIMARY KEY (OfferNo)
);

INSERT INTO Offering
	(OfferNo, CourseNo, OffTerm, OffYear, OffLocation, OffTime, FacNo, OffDays)
	VALUES (1111,'IS320','SUMMER',2020,'BLM302','10:30:00',NULL,'MW');
	
INSERT INTO Offering
	(OfferNo, CourseNo, OffTerm, OffYear, OffLocation, OffTime, FacNo, OffDays)
	VALUES (1234,'IS320','FALL',2019,'BLM302','10:30:00','098-76-5432','MW');
	
INSERT INTO Offering
	(OfferNo, CourseNo, OffTerm, OffYear, OffLocation, OffTime, FacNo, OffDays)
	VALUES (2222,'IS460','SUMMER',2019,'BLM412','13:30:00',NULL,'TTH');
	
INSERT INTO Offering
	(OfferNo, CourseNo, OffTerm, OffYear, OffLocation, OffTime, FacNo, OffDays)
	VALUES (3333,'IS320','SPRING',2020,'BLM214','08:30:00','098-76-5432','MW');
	
INSERT INTO Offering
	(OfferNo, CourseNo, OffTerm, OffYear, OffLocation, OffTime, FacNo, OffDays)
	VALUES (4321,'IS320','FALL',2019,'BLM214','15:30:00','098-76-5432','TTH');
	
INSERT INTO Offering
	(OfferNo, CourseNo, OffTerm, OffYear, OffLocation, OffTime, FacNo, OffDays)
	VALUES (4444,'IS320','WINTER',2020,'BLM302','15:30:00','543-21-0987','TTH');
	
INSERT INTO Offering
	(OfferNo, CourseNo, OffTerm, OffYear, OffLocation, OffTime, FacNo, OffDays)
	VALUES (5555,'FIN300','WINTER',2020,'BLM207','08:30:00','765-43-2109','MW');
	
INSERT INTO Offering
	(OfferNo, CourseNo, OffTerm, OffYear, OffLocation, OffTime, FacNo, OffDays)
	VALUES (5678,'IS480','WINTER',2020,'BLM302','10:30:00','987-65-4321','MW');
	
INSERT INTO Offering
	(OfferNo, CourseNo, OffTerm, OffYear, OffLocation, OffTime, FacNo, OffDays)
	VALUES (5679,'IS480','SPRING',2020,'BLM412','15:30:00','876-54-3210','TTH');
	
INSERT INTO Offering
	(OfferNo, CourseNo, OffTerm, OffYear, OffLocation, OffTime, FacNo, OffDays)
	VALUES (6666,'FIN450','WINTER',2020,'BLM212','10:30:00','987-65-4321','TTH');
	
INSERT INTO Offering
	(OfferNo, CourseNo, OffTerm, OffYear, OffLocation, OffTime, FacNo, OffDays)
	VALUES (7777,'FIN480','SPRING',2020,'BLM305','13:30:00','765-43-2109','MW');
	
INSERT INTO Offering
	(OfferNo, CourseNo, OffTerm, OffYear, OffLocation, OffTime, FacNo, OffDays)
	VALUES (8888,'IS320','SUMMER',2020,'BLM405','13:30:00','654-32-1098','MW');
	
INSERT INTO Offering
	(OfferNo, CourseNo, OffTerm, OffYear, OffLocation, OffTime, FacNo, OffDays)
	VALUES (9876,'IS460','SPRING',2020,'BLM307','13:30:00','654-32-1098','TTH');
	
