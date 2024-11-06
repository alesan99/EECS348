--1
SELECT StdFirstName, StdLastName, StdCity, StdGPA
FROM Student
WHERE StdGPA > 3.7;

--2
SELECT StdFirstName, StdLastName, StdGPA
FROM Student
ORDER BY StdGPA DESC;

--3
SELECT *
FROM course
WHERE CourseNo LIKE 'IS4%';

--4
SELECT OfferNo, CourseNo
FROM Offering
WHERE FacNo IS NULL AND OffTerm = 'SUMMER';

--5
SELECT Offering.OfferNo, Offering.CourseNo, Faculty.FacFirstName, Faculty.FacLastName
FROM Offering
JOIN Faculty ON Offering.FacNo = Faculty.FacNo
WHERE Offering.OffTerm = 'SPRING' AND Faculty.FacRank = 'ASST';

--6 
SELECT DISTINCT FacNo
FROM Offering;

--7
SELECT StdFirstName AS FirstName
FROM Student
WHERE StdCity = 'Bothell'
UNION
SELECT FacFirstName AS FirstName
FROM Faculty
WHERE FacCity = 'Bellevue';

--8
INSERT INTO Student (StdNo, StdFirstName, StdLastName, StdCity, StdState, StdZip, StdMajor, StdClass, StdGPA)
VALUES ('999-99-9999', 'JOHN', 'DOE', 'LAWRENCE', 'KS', '66045', 'FIN', 'FR', 4.0);
--print the result
SELECT * FROM Student;

--9
UPDATE Student
SET StdMajor = 'ACCT'
WHERE StdFirstName = 'HOMER' AND StdLastName = 'WELLS';
--print the result
SELECT * FROM Student;

--10
SELECT Student.*
FROM Student
JOIN Faculty ON Student.StdNo = Faculty.FacNo;