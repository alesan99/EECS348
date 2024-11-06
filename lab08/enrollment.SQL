-- Works for both Oracle and PostgreSQL

Drop table if exists Enrollment;

CREATE TABLE Enrollment (
OfferNo		INTEGER,
StdNo		CHAR(11),
EnrGrade	DECIMAL(3,2),
PRIMARY KEY (OfferNo, StdNo)
);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(1234,'123-45-6789',3.30);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(1234,'234-56-7890',3.50);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(1234,'345-67-8901',3.20);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(1234,'456-78-9012',3.10);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(1234,'567-89-0123',3.80);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(1234,'678-90-1234',3.40);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(4321,'123-45-6789',3.50);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(4321,'124-56-7890',3.20);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(4321,'789-01-2345',3.50);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(4321,'876-54-3210',3.10);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(4321,'890-12-3456',3.40);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(4321,'901-23-4567',3.10);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(5555,'123-45-6789',3.20);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(5555,'124-56-7890',2.70);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(5678,'123-45-6789',3.20);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(5678,'234-56-7890',2.80);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(5678,'345-67-8901',3.30);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(5678,'456-78-9012',3.40);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(5678,'567-89-0123',2.60);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(5679,'123-45-6789',2.00);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(5679,'124-56-7890',3.70);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(5679,'678-90-1234',3.30);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(5679,'789-01-2345',3.80);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(5679,'890-12-3456',2.9);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(5679,'901-23-4567',3.1);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(6666,'234-56-7890',3.1);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(6666,'567-89-0123',3.6);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(7777,'876-54-3210',3.4);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(7777,'890-12-3456',3.7);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(7777,'901-23-4567',3.4);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(9876,'124-56-7890',3.5);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(9876,'234-56-7890',3.2);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(9876,'345-67-8901',3.2);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(9876,'456-78-9012',3.4);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(9876,'567-89-0123',2.6);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(9876,'678-90-1234',3.3);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(9876,'901-23-4567',4);

INSERT INTO Enrollment
	(OfferNO, StdNo, EnrGrade)
	VALUES(1111,'901-23-4567',0.0);
