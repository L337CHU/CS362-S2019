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

    public void test() {
    }
}

