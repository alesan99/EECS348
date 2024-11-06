-- Executes in both Oracle and PostgreSQL
Drop table if exists Course;

CREATE TABLE course (
CourseNo	CHAR(6),
CrsDesc		VARCHAR(50),
CrsUnits	INTEGER,
PRIMARY KEY (CourseNo)
);

-- INSERT statements to populate table
INSERT INTO course
	(CourseNo, CrsDesc, CrsUnits)
	VALUES ( 'FIN300','FUNDAMENTALS OF FINANCE',4);

INSERT INTO course
	(CourseNo, CrsDesc, CrsUnits)
	VALUES ( 'FIN450','PRINCIPLES OF INVESTMENTS',4);
	
INSERT INTO course
	(CourseNo, CrsDesc, CrsUnits)
	VALUES ( 'FIN480','CORPORATE FINANCE',4);
	
INSERT INTO course
	(CourseNo, CrsDesc, CrsUnits)
	VALUES ('IS320','FUNDAMENTALS OF BUSINESS PROGRAMMING',4 );

INSERT INTO course
	(CourseNo, CrsDesc, CrsUnits)
	VALUES ( 'IS460','SYSTEMS ANALYSIS',4);
	
INSERT INTO course
	(CourseNo, CrsDesc, CrsUnits)
	VALUES ( 'IS470','BUSINESS DATA COMMUNICATIONS',4);

INSERT INTO course
	(CourseNo, CrsDesc, CrsUnits)
	VALUES ('IS480','FUNDAMENTALS OF DATABASE MANAGEMENT',4 );

		
