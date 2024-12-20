-- Keep a log of any SQL queries you execute as you solve the mystery.
-- .schema for general knowledge
-- First, let's check the crime scene reports to gather information about the crime.
-- SELECT * FROM crime_scene_reports;

-- see the interviews conducted to gather any potential suspects or witnesses.
-- SELECT * FROM interviews;

-- looking for any ATM transactions that occurred around the time of the crime, as they might provide leads on suspects.
-- SELECT * FROM atm_transactions WHERE year = 2024 AND month = 11;  -- Adjust the year/month based on the crime date.

-- checking the bank accounts to find any suspicious transactions that might relate to the crime.
-- SELECT * FROM bank_accounts;

-- which airports are in the city to track any potential flight activity related to the thief.
-- SELECT * FROM airports;

-- see if any flights were taken around the time of the crime to identify possible escape routes.
-- SELECT * FROM flights WHERE year = 2024 AND month = 11;  -- Again, adjust based on the crime date.

-- check the passengers on the flights to see if any known suspects were on them.
-- SELECT * FROM passengers;

-- looking for phone call logs, as they might reveal communication between the thief and any accomplices.
-- SELECT * FROM phone_calls;

-- checking the bakery security logs to see if any suspicious activity was recorded.
-- SELECT * FROM bakery_security_logs;

