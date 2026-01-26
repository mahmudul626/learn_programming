/*
 * Calculates the library fine based on the return date and due date.
 * * Rules:
 * 1. If returned on or before the due date, fine = 0.
 * 2. If returned late within the same month and year, fine = 15 * (days late).
 * 3. If returned late after the due month but within the same year, fine = 500 * (months late).
 * 4. If returned after the due year, a fixed fine of 10000 is applied.
 * * Parameters:
 * d1, m1, y1: actual return date (day, month, year)
 * d2, m2, y2: expected due date (day, month, year)
 * Returns: The calculated fine as an integer.
 */



int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {

    if (y1 > y2)
        return 10000;
        
    
    if (y1 == y2)
        if (m1 > m2)
            return 500*(m1-m2);

        
        if (m1 == m2)  
            if (d1 > d2) 
                return 15 * (d1-d2);

return 0;
}