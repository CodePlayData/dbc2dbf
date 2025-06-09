import {createRequire} from 'module';

const require = createRequire(import.meta.url);
const { dbc2dbf } = require('../build/Release/addon');

export {
    dbc2dbf
}