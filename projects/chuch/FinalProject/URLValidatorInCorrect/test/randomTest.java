/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import junit.framework.TestCase;


/**
 * testrandomTest for creating randomized tests w/ varying set of inputs
 *
 * @version $Revision$
 */
public class randomTest extends TestCase {

    public randomTest(String testName){
        super(testName);
    }

    public void testScheme() {

        //no parameters are passed to UrlValidator so defaulted to DEFAULT_SCHEMES in UrlValidator
        UrlValidator urlVal = new UrlValidator();

        //testing different schemes
        assertTrue(urlVal.isValidScheme("http"));
        assertTrue(urlVal.isValidScheme("https"));
        assertTrue(urlVal.isValidScheme("ftp"));

        //use isValid to test wwww.google.com without the valid schemes
        assertFalse(urlVal.isValid("www.google.com"));

        //list the correct default schemes possibilities
        String[] correctSchemes = {"http", "https", "ftp"};

        //iterate through 10 schemes possibilities
        for(int i=0; i < 10; i++){
            int random =(int)(Math.random() * 2 + 0);
            String urlCheck = correctSchemes[random] + "://www.google.com";
            assertTrue(urlVal.isValid(urlCheck));
        }

       // assertTrue(urlVal.isValid("ftp://www.google.com"));
        //assertFalse(urlVal.isValid("hstps://www.google.com"));
    }

    public void testAuthority() {
        UrlValidator urlValTwo = new UrlValidator(UrlValidator.ALLOW_LOCAL_URLS);
        String[] validPorts = {":80",":32562",":45802", ":230", ":23456"};
        String[] invalidPorts = {":-23", ":67235", ":65600", ":-80", ":-1"};
        String[] defaultSchemes = {"http", "https", "ftp"};

        //authority can include the hostname and port
        //assertTrue(urlValTwo.isValidAuthority("localhost:65600"));

        //iterate through 10 validPorts and invalidPorts
        for(int i=0; i < 10; i++){
            int randomPort = (int)(Math.random() * 4 + 0);

            //combine host and port strings
            String auth = "localhost" + validPorts[randomPort];
            String invalidAuth = "localhost" + invalidPorts[randomPort];

            //tests to see if randomized valid and randomized invalidPorts pass tests
            //use isValidAuthority method
            assertTrue(urlValTwo.isValidAuthority(auth));
            assertFalse(urlValTwo.isValidAuthority(invalidAuth));

        }
        //iterate through 10 urls including the schemes with localhost and validPorts and call isValid
        for(int i=0; i < 10; i++){
            int randomPort = (int)(Math.random() * 4 + 0);
            int randomSch = (int)(Math.random() * 2 + 0);

            //combined components for URL
            String url = defaultSchemes[randomSch] + "://localhost" + validPorts[randomPort];
            String urlTwo = defaultSchemes[randomSch] + "://localhost" + invalidPorts[randomPort];

            //call isValid
            assertTrue(urlValTwo.isValid(url));
            assertFalse(urlValTwo.isValid(urlTwo));

        }

    }
    public void testPath(){
        String [] validPaths = {"/path", "/Diff", "/DiffTwo", "/path/pathTwo", "/path/path/path"};

        //no parameters are passed to UrlValidator so defaulted to DEFAULT_SCHEMES in UrlValidator
        UrlValidator urlVal = new UrlValidator();

        //test w/out path using default scheme
        assertTrue(urlVal.isValid("https://www.google.com"));

        //test local url, then w/ allowlocal method
        assertFalse(urlVal.isValid("https://localhost:80"));
        urlVal = new UrlValidator(UrlValidator.ALLOW_LOCAL_URLS);
        assertTrue(urlVal.isValid("https://localhost:80"));

        //combinedURL
        int random = (int)(Math.random() * 5 + 0);
        //System.out.println(random);
        String combine = "https://www.google.com" + validPaths[random];
        String combineTwo = "https://localhost:80" + validPaths[random];
        assertTrue(urlVal.isValid(combine));
        assertTrue(urlVal.isValid(combineTwo));

    }

    public void testFinal() {
        UrlValidator urlVal = new UrlValidator(UrlValidator.NO_FRAGMENTS);

        //set example query and test to see if its valid
        String exQuery = "?test=number&example=number";
        assertTrue(urlVal.isValidQuery(exQuery));

        //test known passed tests
        String correctUrl = "https://www.google.com:80/path/";
        assertTrue(urlVal.isValid(correctUrl));

        //add with query
        String combinedUrl = correctUrl + exQuery;
        assertTrue(urlVal.isValid(combinedUrl));

        //check permutations
        String[] validPaths = {"/path/", "/Diff/", "/DiffTwo/"};
        String[] validPorts = {":80",":32562",":45802"};
        String[] correctSchemes = {"http://", "https://", "ftp://"};
        String[] common = {"www.google.com", "www.yahoo.com", "www.cnn.com"};

        //The only correct combination of componenets is schemes + host + port + query
        int random = (int)(Math.random() * 3 + 0);
        String permOne = correctSchemes[random] + common[random] + validPorts[random] + validPaths[random] + exQuery ;
        assertTrue(urlVal.isValid(permOne));

        String permTwo = common[random] +correctSchemes[random]+ validPorts[random] + validPaths[random] + exQuery;
        assertFalse(urlVal.isValid(permTwo));

        String permThree = validPorts[random] + validPaths[random] + correctSchemes[random] + common[random] + exQuery;
        assertFalse(urlVal.isValid(permThree));

        String permFour = validPaths[random] +correctSchemes[random] + common[random] + exQuery + validPorts[random];
        assertFalse(urlVal.isValid(permFour));

        String permFive = correctSchemes[random] + validPorts[random] + exQuery + common[random] + validPaths[random];
        assertFalse(urlVal.isValid(permFive));




    }
}

