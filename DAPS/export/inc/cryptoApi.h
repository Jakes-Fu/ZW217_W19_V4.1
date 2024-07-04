/*
 *	cryptoApi.h
 *	Release $Name: MATRIXSSL-3-4-2-COMM $
 *
 *	Prototypes for the Matrix crypto public APIs
 */
/*
 *	Copyright (c) 2013 INSIDE Secure Corporation
 *	All Rights Reserved
 *
 *	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF INSIDE.
 *
 *	Please do not edit this file without first consulting INSIDE support.
 *	Unauthorized changes to this file are not supported by INSIDE.
 *
 *	The copyright notice above does not evidence any actual or intended
 *	publication of such source code.
 *
 *	This Module contains Proprietary Information of INSIDE and should be
 *	treated as Confidential.
 *
 *	The information in this file is provided for the exclusive use of the
 *	licensees of INSIDE. Such users have the right to use, modify,
 *	and incorporate this code into products for purposes authorized by the
 *	license agreement provided they include this notice and the associated
 *	copyright notice with any such product.
 *
 *	The information in this file is provided "AS IS" without warranty.
 */
/******************************************************************************/

#ifndef _h_PS_CRYPTOAPI
#define _h_PS_CRYPTOAPI

#include "coreApi.h" /* Must be first included */
#include "cryptoConfig.h" /* Must be second included */
#include "cryptolib.h"
#include "symmetric.h"
/******************************************************************************/
/*	Public return codes */
/******************************************************************************/
/*	Failure codses MUST be < 0  */
/*	NOTE: The range for crypto error codes must be between -30 and -49  */
#define	PS_PARSE_FAIL			-31

/*
	PS NOTE:  Any future additions to certificate authentication failures
	must be carried through to MatrixSSL code
*/	
#define PS_CERT_AUTH_PASS	PS_TRUE
#define	PS_CERT_AUTH_FAIL_BC	-32 /* BasicConstraint failure */
#define	PS_CERT_AUTH_FAIL_DN	-33 /* DistinguishedName failure */
#define	PS_CERT_AUTH_FAIL_SIG	-34 /* Signature validation failure */
#define PS_CERT_AUTH_FAIL_REVOKED -35 /* Revoked via CRL */
#define	PS_CERT_AUTH_FAIL		-36 /* Generic cert auth fail */

#define PS_SIGNATURE_MISMATCH	-37 /* Alorithms all work but sig not a match */

/******************************************************************************/
/* Public APIs */
/******************************************************************************/
#ifdef USE_AES
/******************************************************************************/
/*
	CBC Mode AES
*/
PSPUBLIC int32 psAesInit(psCipherContext_t *ctx, unsigned char *IV,
						unsigned char *key, uint32 keylen);
PSPUBLIC int32 psAesDecrypt(psCipherContext_t *ctx, unsigned char *ct,
						unsigned char *pt, uint32 len);
PSPUBLIC int32 psAesEncrypt(psCipherContext_t *ctx, unsigned char *pt,
						unsigned char *ct, uint32 len);
/*
	Block Mode AES
*/
PSPUBLIC int32 psAesInitKey(const unsigned char *key, uint32 keylen,
						psAesKey_t *skey);
PSPUBLIC void psAesEncryptBlock(const unsigned char *pt, unsigned char *ct,
						psAesKey_t *skey);
PSPUBLIC void psAesDecryptBlock(const unsigned char *ct, unsigned char *pt,
						psAesKey_t *skey);


#ifdef USE_AES_GCM
PSPUBLIC int32 psAesInitGCM(psCipherContext_t *ctx, unsigned char *key,
				int32 keylen);
PSPUBLIC int32 psAesReadyGCM(psCipherContext_t *ctx, unsigned char *IV,
					unsigned char *aad,	int32 aadLen);				
PSPUBLIC int32 psAesEncryptGCM(psCipherContext_t *ctx, unsigned char *pt,
			unsigned char *ct, int32 len);
PSPUBLIC int32 psAesGetGCMTag(psCipherContext_t *ctx, int32 TagBytes,
			unsigned char *tag);
PSPUBLIC int32 psAesDecryptGCM(psCipherContext_t *ctx, unsigned char *ct,
			int32 ctLen, unsigned char *pt, int32 ptLen);
							
#endif /* USE_AES_GCM */			
#endif /* USE_AES */
/******************************************************************************/

/******************************************************************************/
/******************************************************************************/
#ifdef USE_SEED
/******************************************************************************/
PSPUBLIC int32 psSeedInit(psCipherContext_t *ctx, unsigned char *IV,
						unsigned char *key, uint32 keylen);
PSPUBLIC int32 psSeedDecrypt(psCipherContext_t *ctx, unsigned char *ct,
						unsigned char *pt, uint32 len);
PSPUBLIC int32 psSeedEncrypt(psCipherContext_t *ctx, unsigned char *pt,
						unsigned char *ct, uint32 len);

PSPUBLIC int32 psSeedInitKey(const unsigned char *key, uint32 keylen,
						psSeedKey_t *skey);
PSPUBLIC void psSeedEncryptBlock(const unsigned char *pt, unsigned char *ct,
						psSeedKey_t *skey);
PSPUBLIC void psSeedDecryptBlock(const unsigned char *ct, unsigned char *pt,
						psSeedKey_t *skey);
#endif /* USE_SEED */
/******************************************************************************/

/******************************************************************************/
#ifdef USE_3DES
/******************************************************************************/
/*
	CBC Mode DES3 
*/
PSPUBLIC int32 psDes3Init(psCipherContext_t *ctx, unsigned char *IV,
						unsigned char *key, uint32 keylen);
PSPUBLIC int32 psDes3Decrypt(psCipherContext_t *ctx, unsigned char *ct,
						unsigned char *pt, uint32 len);
PSPUBLIC int32 psDes3Encrypt(psCipherContext_t *ctx, unsigned char *pt,
						unsigned char *ct, uint32 len);
/*
	Block Mode DES3 
*/
PSPUBLIC int32 psDes3InitKey(const unsigned char *key, uint32 keylen,
						psDes3Key_t *skey);
PSPUBLIC void psDes3EncryptBlock(const unsigned char *pt, unsigned char *ct,
						psDes3Key_t *skey);
PSPUBLIC void psDes3DecryptBlock(const unsigned char *ct, unsigned char *pt,
						psDes3Key_t *skey);
#endif /* USE_3DES */
/******************************************************************************/

/******************************************************************************/
#ifdef USE_DES
//add by li.li
PSPUBLIC int32 psDesInit(psCipherContext_t *ctx, unsigned char *IV,
						unsigned char *key, uint32 keylen);
PSPUBLIC int32 psDesDecrypt(psCipherContext_t *ctx, unsigned char *ct,
						unsigned char *pt, uint32 len);
PSPUBLIC int32 psDesEncrypt(psCipherContext_t *ctx, unsigned char *pt,
						unsigned char *ct, uint32 len);
//add end li.li
PSPUBLIC int32 psDesInitKey(const unsigned char *key, int32 keylen,
						psDes3Key_t *skey);
PSPUBLIC void psDesEncryptBlock(const unsigned char *pt, unsigned char *ct,
						psDes3Key_t *skey);
PSPUBLIC void psDesDecryptBlock(const unsigned char *ct, unsigned char *pt,
						psDes3Key_t *skey);
#endif /* USE_DES */
/******************************************************************************/

/******************************************************************************/
#ifdef USE_ARC4
PSPUBLIC void psArc4Init(psCipherContext_t *ctx, unsigned char *key,
						uint32 keylen);
PSPUBLIC int32 psArc4(psCipherContext_t *ctx, unsigned char *in,
						unsigned char *out, uint32 len);
#endif /* USE_ARC4 */
/******************************************************************************/

#ifdef USE_RC2
/******************************************************************************/
PSPUBLIC int32 psRc2Init(psCipherContext_t *ctx, unsigned char *IV,
						unsigned char *key, uint32 keylen);
PSPUBLIC int32 psRc2Decrypt(psCipherContext_t *ctx, unsigned char *ct,
						unsigned char *pt, uint32 len);
PSPUBLIC int32 psRc2Encrypt(psCipherContext_t *ctx, unsigned char *pt,
						unsigned char *ct, uint32 len);
PSPUBLIC int32 psRc2InitKey(unsigned char *key, uint32 keylen, uint32 rds,
						psRc2Key_t *skey);
PSPUBLIC int32 psRc2EncryptBlock(unsigned char *pt, unsigned char *ct,
						psRc2Key_t *skey);
PSPUBLIC int32 psRc2DecryptBlock(unsigned char *ct, unsigned char *pt,
						psRc2Key_t *skey);					
#endif /* USE_RC2 */
#ifdef USE_RC5 // add by li.li
int32 psRC5Init(psCipherContext_t *ctx, unsigned char *IV,int round,
				   unsigned char *key, int32 keylen);
int32 psRC5Encrypt(psCipherContext_t *ctx, unsigned char *pt,
					  unsigned char *ct, uint32 len);
int32 psRC5Decrypt(psCipherContext_t *ctx, unsigned char *ct,
					  unsigned char *pt, uint32 len);
#endif // add end by li.li
/******************************************************************************/
/******************************************************************************/
#ifdef USE_SHA1
/******************************************************************************/
PSPUBLIC void psSha1Init(psDigestContext_t * md);
PSPUBLIC void psSha1Update(psDigestContext_t * md, const unsigned char *buf,
				uint32 len);
PSPUBLIC int32 psSha1Final(psDigestContext_t * md, unsigned char *hash);

#ifdef USE_HMAC
PSPUBLIC int32 psHmacSha1(unsigned char *key, uint32 keyLen,
				const unsigned char *buf, uint32 len,
				unsigned char *hash, unsigned char *hmacKey,
				uint32 *hmacKeyLen);
PSPUBLIC void psHmacSha1Init(psHmacContext_t *ctx, unsigned char *key,
				uint32 keyLen);
PSPUBLIC void psHmacSha1Update(psHmacContext_t *ctx, const unsigned char *buf,
				uint32 len);
PSPUBLIC int32 psHmacSha1Final(psHmacContext_t *ctx, unsigned char *hash); 
#endif /* USE_HMAC */
#endif /* USE_SHA1 */
/******************************************************************************/

/******************************************************************************/
#ifdef USE_SHA256
#ifdef USE_HMAC
PSPUBLIC int32 psHmacSha2(unsigned char *key, uint32 keyLen,
				const unsigned char *buf, uint32 len,
				unsigned char *hash, unsigned char *hmacKey,
				uint32 *hmacKeyLen, uint32 hashSize);
PSPUBLIC void psHmacSha2Init(psHmacContext_t *ctx, unsigned char *key,
				uint32 keyLen, uint32 hashSize);
PSPUBLIC void psHmacSha2Update(psHmacContext_t *ctx, const unsigned char *buf,
				uint32 len, uint32 hashSize);
PSPUBLIC int32 psHmacSha2Final(psHmacContext_t *ctx, unsigned char *hash,
				uint32 hashSize); 
#endif /* USE_HMAC */
/******************************************************************************/
PSPUBLIC void psSha256Init(psDigestContext_t * md);
PSPUBLIC void psSha256Update(psDigestContext_t * md, const unsigned char *buf,
				uint32 len);
PSPUBLIC int32 psSha256Final(psDigestContext_t * md, unsigned char *hash);
#endif /* USE_SHA256 */


#ifdef USE_SHA224
PSPUBLIC void psSha224Init(psDigestContext_t * md);
PSPUBLIC void psSha224Update(psDigestContext_t * md, const unsigned char *buf,
				uint32 len);
PSPUBLIC int32 psSha224Final(psDigestContext_t * md, unsigned char *hash);
#endif /* USE_SHA224 */

#ifdef USE_SHA384
PSPUBLIC void psSha384Init(psDigestContext_t * md);
PSPUBLIC void psSha384Update(psDigestContext_t * md, const unsigned char *buf,
				uint32 len);
PSPUBLIC int32 psSha384Final(psDigestContext_t * md, unsigned char *hash);
#endif /* USE_SHA384 */

#ifdef USE_SHA512
PSPUBLIC void psSha512Init(psDigestContext_t * md);
PSPUBLIC void psSha512Update(psDigestContext_t * md, const unsigned char *buf,
				uint32 len);
PSPUBLIC int32 psSha512Final(psDigestContext_t * md, unsigned char *hash);
#endif /* USE_SHA224 */

/******************************************************************************/

#ifdef USE_ECC
PSPUBLIC int32 psEcdsaParsePrivKey(psPool_t *pool, unsigned char *keyBuf,
				int32 keyBufLen, psPubKey_t **keyPtr, psEccSet_t *curve);
PSPUBLIC int32 psEcdsaParsePrivFile(psPool_t *pool, char *fileName,
				char *password,	psPubKey_t **outkey);
PSPUBLIC int32 psEccX963ImportKey(psPool_t *pool, const unsigned char *inbuf,
				uint32 inlen, psEccKey_t *key);
PSPUBLIC int32 psEccX963ExportKey(psPool_t *pool, psEccKey_t *key,
				unsigned char *outbuf, uint32 *outlen);
PSPUBLIC int32 psEccMakeKeyEx(psPool_t *pool, psEccKey_t **keyPtr,
				psEccSet_t *dp);
PSPUBLIC void psEccFreeKey(psEccKey_t **key);
PSPUBLIC int32 psEccGenSharedSecret(psPool_t *pool, psEccKey_t *private_key,
				psEccKey_t *public_key, unsigned char *outbuf,
				uint32 *outlen);
PSPUBLIC int32 psEcDsaValidateSignature(psPool_t *pool, psEccKey_t *myPubKey,
				unsigned char *signature, int32 sigLen,	unsigned char *hash,
				int32 hashLen, int32 *stat);
PSPUBLIC int32 psEccSignHash(psPool_t *pool, unsigned char *inbuf,
				int32 inlen, unsigned char *c, int32 outlen,
				psEccKey_t *privKey, int32 *bytesWritten);
#endif /* USE_ECC */
/******************************************************************************/

/******************************************************************************/
#ifdef USE_MD5
/******************************************************************************/
PSPUBLIC void psMd5Init(psDigestContext_t * md);
PSPUBLIC void psMd5Update(psDigestContext_t * md, const unsigned char *buf,
				uint32 len);
PSPUBLIC int32 psMd5Final(psDigestContext_t * md, unsigned char *hash);

#ifdef USE_HMAC
PSPUBLIC int32 psHmacMd5(unsigned char *key, uint32 keyLen,
				const unsigned char *buf, uint32 len,
				unsigned char *hash, unsigned char *hmacKey,
				uint32 *hmacKeyLen);
PSPUBLIC void psHmacMd5Init(psHmacContext_t *ctx, unsigned char *key,
				uint32 keyLen);
PSPUBLIC void psHmacMd5Update(psHmacContext_t *ctx, const unsigned char *buf,
				uint32 len);
PSPUBLIC int32 psHmacMd5Final(psHmacContext_t *ctx, unsigned char *hash); 
#endif /* USE_HMAC */
#endif /* USE_MD5 */
/******************************************************************************/

/******************************************************************************/
#ifdef USE_MD4
/******************************************************************************/
PSPUBLIC void psMd4Init(psDigestContext_t * md);
PSPUBLIC void psMd4Update(psDigestContext_t * md, const unsigned char *buf,
				uint32 len);
PSPUBLIC int32 psMd4Final(psDigestContext_t * md, unsigned char *hash);
#endif /* USE_MD4 */
/******************************************************************************/

/******************************************************************************/
#ifdef USE_MD2
/******************************************************************************/
PSPUBLIC void psMd2Init(psDigestContext_t * md);
PSPUBLIC int32 psMd2Update(psDigestContext_t * md, const unsigned char *buf,
				uint32 len);
PSPUBLIC int32 psMd2Final(psDigestContext_t * md, unsigned char *hash);
#endif /* USE_MD2 */
/******************************************************************************/

/******************************************************************************/
/*
	Private Key Parsing
	PKCS#1 - RSA specific
	PKCS#8 - General private key storage format
*/
#ifdef USE_PRIVATE_KEY_PARSING
#ifdef USE_RSA
PSPUBLIC int32 pkcs1ParsePrivBin(psPool_t *pool, unsigned char *p,
				uint32 size, psPubKey_t **key);
#ifdef MATRIX_USE_FILE_SYSTEM
PSPUBLIC int32 pkcs1ParsePrivFile(psPool_t *pool, char *fileName,
				char *password, psPubKey_t **outkey);
#endif /* MATRIX_USE_FILE_SYSTEM */				
#endif /* USE_RSA */
		
#ifdef MATRIX_USE_FILE_SYSTEM
PSPUBLIC int32 pkcs1DecodePrivFile(psPool_t *pool, char *fileName,
				char *password,	unsigned char **DERout, uint32 *DERlen);
#endif /* MATRIX_USE_FILE_SYSTEM */
						
#ifdef USE_PKCS8
PSPUBLIC int32 pkcs8ParsePrivBin(psPool_t *pool, unsigned char *p,
				int32 size, char *pass, psPubKey_t **key);
#ifdef MATRIX_USE_FILE_SYSTEM
#ifdef USE_PKCS12				
PSPUBLIC int32 psPkcs12Parse(psPool_t *pool, psX509Cert_t **cert,
				psPubKey_t **privKey, const unsigned char *file, int32 flags,
				unsigned char *importPass, int32 ipasslen,
				unsigned char *privkeyPass, int32 kpasslen);
#endif /* USE_PKCS12 */
#endif /* MATRIX_USE_FILE_SYSTEM */				
#endif /* USE_PKCS8 */
#endif /* USE_PRIVATE_KEY_PARSING */

/******************************************************************************/

/******************************************************************************/
#ifdef USE_PKCS5
/******************************************************************************/
/*
	PKCS#5 PBKDF v1 and v2 key generation
*/
PSPUBLIC void pkcs5pbkdf1(unsigned char *pass, uint32 passlen,
				unsigned char *salt, int32 iter, unsigned char *key);
PSPUBLIC void pkcs5pbkdf2(unsigned char *password, uint32 pLen, 
				 unsigned char *salt, uint32 sLen, int32 rounds,
				 unsigned char *key, uint32 kLen);
#endif /* USE_PKCS5 */

/******************************************************************************/
/*
	Public Key Cryptography
*/
PSPUBLIC psPubKey_t *psNewPubKey(psPool_t *pool);
PSPUBLIC void psFreePubKey(psPubKey_t *key);
PSPUBLIC int32 psEstimatePkiPoolSize(uint32 keylen, 
				unsigned short *pubSize, unsigned short *privSize, int32 type);

/******************************************************************************/
#ifdef USE_RSA
/******************************************************************************/
/*
	RSA crypto
*/

PSPUBLIC int32 psRsaDecryptPriv(psPool_t *pool, psRsaKey_t *key,
					unsigned char *in, uint32 inlen,
					unsigned char *out, uint32 outlen, void *data);
PSPUBLIC int32 psRsaDecryptPub(psPool_t *pool, psRsaKey_t *key,
					unsigned char *in, uint32 inlen,
					unsigned char *out, uint32 outlen, void *data);
PSPUBLIC int32 psRsaEncryptPub(psPool_t *pool, psRsaKey_t *key,
				unsigned char *in, uint32 inlen,
				unsigned char *out, uint32 outlen, void *data);
PSPUBLIC int32 pubRsaDecryptSignedElement(psPool_t *pool, psPubKey_t *key, 
				unsigned char *in, uint32 inlen, unsigned char *out,
				uint32 outlen, void *data);
PSPUBLIC int32 psRsaEncryptPriv(psPool_t *pool, psRsaKey_t *key,
					unsigned char *in, uint32 inlen,
					unsigned char *out, uint32 outlen, void *data);
PSPUBLIC int32 privRsaEncryptSignedElement(psPool_t *pool, psPubKey_t *key,
				unsigned char *in, uint32 inlen, unsigned char *out,
				uint32 outlen, void *data);										
#ifdef USE_PKCS1_OAEP					
PSPUBLIC int32 pkcs1OaepEncode(psPool_t *pool, const unsigned char *msg,
				uint32 msglen, const unsigned char *lparam,
				uint32 lparamlen, unsigned char *seed, uint32 seedLen,
				uint32 modulus_bitlen, int32 hash_idx,
				unsigned char *out, uint32 *outlen);
PSPUBLIC int32 pkcs1OaepDecode(psPool_t *pool, const unsigned char *msg,
				uint32 msglen, const unsigned char *lparam, uint32 lparamlen,
				uint32 modulus_bitlen, int32 hash_idx,
				unsigned char *out, uint32 *outlen);
#endif /* USE_PKCS1_OAEP */

#ifdef USE_PKCS1_PSS
PSPUBLIC int32 pkcs1PssEncode(psPool_t *pool, const unsigned char *msghash,
			uint32 msghashlen, unsigned char *salt, uint32 saltlen,
			int32 hash_idx,	uint32 modulus_bitlen, unsigned char *out,
			uint32 *outlen);
PSPUBLIC int32 pkcs1PssDecode(psPool_t *pool, const unsigned char *msghash,
			uint32 msghashlen, const unsigned char *sig, uint32 siglen,
			uint32 saltlen, int32 hash_idx, uint32 modulus_bitlen, int32 *res);			
#endif /* USE_PKCS1_PSS */
PSPUBLIC int32 psRsaCrypt(psPool_t *pool, const unsigned char *in, uint32 inlen,
				unsigned char *out, uint32 *outlen,	psRsaKey_t *key,
				int32 type, void *data);
#endif /* USE_RSA */
/******************************************************************************/

/******************************************************************************/
#ifdef USE_DH
/******************************************************************************/
/******************************************************************************/
/*
	PKCS#3 - Diffie-Hellman parameters
*/
PSPUBLIC int32 pkcs3ParseDhParamBin(psPool_t *pool, unsigned char *dhBin,
					int32 dhBinLen, psDhParams_t **key);
#ifdef MATRIX_USE_FILE_SYSTEM
PSPUBLIC int32 pkcs3ParseDhParamFile(psPool_t *pool, char *fileName,
					 psDhParams_t **key);
#endif /* MATRIX_USE_FILE_SYSTEM */
PSPUBLIC void pkcs3FreeDhParams(psDhParams_t *params);


PSPUBLIC int32 psDhKeyGen(psPool_t *pool, uint32 keysize, unsigned char *pBin,
					uint32 pLen, unsigned char *gBin, uint32 gLen,
					psDhKey_t *key);					
PSPUBLIC int32 psDhKeyGenInts(psPool_t *pool, uint32 keysize, pstm_int *p,
					pstm_int *g, psDhKey_t *key);
					
PSPUBLIC int32 psDhGenSecret(psPool_t *pool, psDhKey_t *private_key,
					psDhKey_t *public_key, unsigned char *pBin, uint32 pLen,
					unsigned char *outbuf, uint32 *outlen);
PSPUBLIC int32 psDhImportPubKey(psPool_t *pool, unsigned char *inbuf,
					uint32 inlen, psDhKey_t *key); 
PSPUBLIC int32 psDhExportPubKey(psPool_t *pool, psDhKey_t *key,
					unsigned char **out);					

PSPUBLIC int32 psDhExportParameters(psPool_t *pool, psDhParams_t *key,
					uint32 *pLen, unsigned char **p, uint32 *gLen,
					unsigned char **g);
PSPUBLIC void psDhFreeKey(psDhKey_t *key);
int DH_Generatekey(int keysize, DH_KEY_T *key,pstm_int *prime,pstm_int *base);
int DH_shared_secret(DH_KEY_T *private_key, DH_KEY_T *public_key,
                     unsigned char *out, unsigned long *outlen);
#endif /* USE_DH */
/******************************************************************************/

/******************************************************************************/
#ifdef USE_X509
/******************************************************************************/
/*
	X.509 Certificate support	
*/
PSPUBLIC int32 psX509ParseCertFile(psPool_t *pool, char *fileName,
					psX509Cert_t **outcert, int32 flags);
PSPUBLIC int32 psX509ParseCert(psPool_t *pool, unsigned char *pp, uint32 size,
					psX509Cert_t **outcert, int32 flags);
PSPUBLIC void psX509FreeCert(psX509Cert_t *cert);
#ifdef USE_CERT_PARSE
PSPUBLIC int32 psX509AuthenticateCert(psPool_t *pool, psX509Cert_t *subjectCert,
					psX509Cert_t *issuerCert);
int32 matrixX509ValidateCertChain(psPool_t *pool, psX509Cert_t *chain, 
							psX509Cert_t **subjectCert, int32 *valid);
#endif
#ifdef USE_CRL
PSPUBLIC int32 psX509ParseCrl(psPool_t *pool, psX509Cert_t *CA, int append,
					unsigned char *crlBin, int32 crlBinLen);
#endif /* USE_CRL */					
#endif /* USE_X509 */
/******************************************************************************/

/******************************************************************************/
PSPUBLIC int32 psInitPrng(psRandom_t *ctx);
PSPUBLIC int32 psGetPrng(psRandom_t *ctx, unsigned char *bytes, uint32 size);
				

#ifdef USE_YARROW
PSPUBLIC int32 psYarrowStart(psYarrow_t *ctx);
PSPUBLIC int32 psYarrowAddEntropy(unsigned char *in, uint32 inlen,
			psYarrow_t *prng);
PSPUBLIC int32 psYarrowReseed(psYarrow_t *ctx);
PSPUBLIC uint32 psYarrowRead(unsigned char *out, uint32 outlen, psYarrow_t *cx);
PSPUBLIC int32 psYarrowDone(psYarrow_t *ctx);
PSPUBLIC int32 psYarrowExport(unsigned char *out, uint32 *outlen,
			psYarrow_t *ctx);
PSPUBLIC int32 psYarrowImport(unsigned char *in, uint32 inlen, psYarrow_t *ctx);
#endif /* USE_YARROW */
/******************************************************************************/

#endif /* _h_PS_CRYPTOAPI */
/******************************************************************************/
